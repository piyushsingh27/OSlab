/*********************************************************
 * 
 * Program to Demonstrate the working of "ls | wc -l"
 * 
**********************************************************/ 


#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
    int my_pipe[2];
    if( -1 == pipe(my_pipe) ) //Creating a Pipe for IPC
    {
        perror("Pipe Failed");
        exit(1);
    }
    
    pid_t PID = fork(); //Forking a Child Process
    if( -1 == PID )
    {
        perror("Fork Failed");
        exit(1);
    }
    
    if( 0 == PID ) //Child Process
    {    
        char* arr2[] = {"ls", NULL};
        close(1); //Closing Stdout
        close(my_pipe[0]); //Closing Read End of Pipe
        dup(my_pipe[1]); //Duplicating Write End of Pipe
        close(my_pipe[1]); //CLosing Write End of pipe
        execv("/bin/ls",arr2); //Executing ls
    }
    else if(  PID > 0 ) //Parent Process
    {
        wait(NULL);
        char* arr2[] = {"wc", "-l" , NULL};
        close(0); //Closing Stdin
        close(my_pipe[1]); //Closing Write End of Pipe
        dup(my_pipe[0]); //Duplicating read  end of pipe
        close(my_pipe[0]); //Closing read end of pipe
        execv("/usr/bin/wc",arr2); //Executing wc -l
        exit(0);

    }
}