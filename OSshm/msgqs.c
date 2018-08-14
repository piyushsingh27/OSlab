#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

typedef struct
{
    long mtype;
    int msg;
}msgstruct;

int main()
{
    key_t key = ftok("msg15", 1);
    printf("key %d\n",key);

    int mkey = msgget(key, 0644|IPC_CREAT);
    printf("Mkey %d\n",mkey);

    msgstruct mymsg;

    mymsg.mtype = 12;
    mymsg.msg = getpid();

    printf("\nID : %d",getpid());

    int error = msgsnd(mkey, &mymsg, sizeof(mymsg)-sizeof(long), 0);
    if(error < 0)
    {
        printf("Could not send Message\n");
		exit(0);
    }
}
 