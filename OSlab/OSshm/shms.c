#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
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

    mymsg->id = 1747203;
    strcpy(mymsg->msg,"Hello World");
    printf("Message Sent!");
    shmdt(mymsg);
}
