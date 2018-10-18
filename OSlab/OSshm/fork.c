#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

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
    }
    else
    {
        printf(" Parent Executing with id : %d and parent id %d\n",getpid(),getppid());
    }
}