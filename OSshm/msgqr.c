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

    msgrcv(mkey, &mymsg, sizeof(mymsg)-sizeof(long), 12, 0);

    printf("%d", mymsg.msg);
}