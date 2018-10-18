#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    pid_t PID;
    PID = fork();

     if( -1 == PID )
    {
        printf("Fork failed\n");
        exit(0);
    }

    if( 0 == PID  )
    {
        printf("Child Executing with id : %d and parent id %d\n",getpid(),getppid());
        //scanf("%d",&PID);
    }
    else
    {
        sleep(15);
        printf(" Parent Executing with id : %d and parent id %d\n",getpid(),getppid());
        int x = 1;
    
        PID = wait(&x);
        printf("Child Terminated with id : %d and status %d\n",PID,x);
    
    
        PID = wait(&x);
        if( -1 == PID )
        {
            if( errno == ECHILD )
            {
                printf("No child exists\n");
            }
        }
        else
            printf("Child Terminated with id : %d and status %d\n",PID,x);
    }
}