#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int id;
    char msg[20];
}message;

int main()
{
    key_t key = ftok("msg16",1);

    int shmid = shmget(key, sizeof(message), 0644|IPC_CREAT);

    message *mymsg = (message *)shmat(shmid, NULL, 0);

    printf("%d\n",mymsg->id);
    printf("%s\n",mymsg->msg);

    shmdt(mymsg);
}