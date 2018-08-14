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
    key_t key = ftok("msg13",1);
    printf("Key : %d\n",key);

    int mkey = msgget( key , 0644 | IPC_CREAT );
    printf("MKey : %d",mkey);

    msgstruct mymsg;
    msgrcv( mkey , &mymsg , sizeof(mymsg)-sizeof(long) , 12 , 0 );

    printf("\n%d",mymsg.msg);
}