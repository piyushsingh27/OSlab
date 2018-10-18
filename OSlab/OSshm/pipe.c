#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t PID;
    
    int arrp[2],arrc[2];

    int res = pipe(arrp);
    if( -1 == res )
    {
        printf("Pipe failed\n");
        exit(0);
    }

    res = pipe(arrc);
    if( -1 == res )
    {
        printf("Pipe failed\n");
        exit(0);
    }


    PID = fork();
    if( -1 == PID )
    {
        printf("Fork failed\n");
        exit(0);
    }

    
    if( 0 == PID  )
    {
        //printf("Child Executing with id : %d and parent id %d\n",getpid(),getppid());
        close(arrp[1]);
        //close(arr[1]);
        char c[1];
  //    printf("here1");
        while( read(arrp[0],c,1) > 0 )
        {
//           printf("here2");
            //printf("%c")
            write(STDOUT_FILENO,c,1);
        }
    //    printf("here3");
    //    close(arrp[0]);
   
        close(arrc[0]);
        write(arrc[1],"Hello from Child",17);
        close(arrc[1]);
    }

    else
    {
        //printf(" Parent Executing with id : %d and parent id %d\n",getpid(),getppid());
        close(arrc[1]);
        close(arrp[1]);
        char c[1];
        while( read(arrc[0],c,1) > 0 )
        {
            write(STDOUT_FILENO,c,1);
        }
        close(arrc[0]);
        close(arrp[0]);
        //write(arrp[1],"Hello from Parent",18);
        
    }
}