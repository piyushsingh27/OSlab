#include <sys/types.h>
#include <sys/ipc.h>

#include <sys/stat.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct
{
    int id;
    char name[15];
}message;

int main()
{
    key_t key = ftok("msg14",12);

    int shmid = shmget( key , sizeof(message) , 0644 | IPC_CREAT );

    message *mymsg = (message *)shmat(shmid,NULL,0);

    mymsg->id = 1004;
    strcpy(mymsg->name,"Time Kharab");

    shmdt(mymsg);
}