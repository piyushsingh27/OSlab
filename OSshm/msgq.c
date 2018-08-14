#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct
{
    long mtype;
    int msg;
}msgstruct;

int main()
{
    key_t key = ftok( "msg13" , 1 );
    printf("Key : %d\n",key);

    int mkey = msgget( key , 0644 | IPC_CREAT ); //msg queue identifier
   
    printf("MKey : %d",mkey);

    msgstruct mymsg;

    mymsg.mtype = 12;
    mymsg.msg = getpid();

    printf("\nId : %d\n",getpid());
   int error =  msgsnd( mkey , &mymsg , sizeof(mymsg) - sizeof(long) , 0 );
   if(error<0)
    {
		printf("Could not send Message\n");
		exit(0);
	}
}