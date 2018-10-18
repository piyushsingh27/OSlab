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

    int shmid = shmget( key , sizeof(message) , IPC_CREAT );

    message *mymsg = (message *)shmat(shmid, NULL, 0);

    printf("ID : %d\n",mymsg->id);
    printf("Name : %s\n",mymsg->name);

    shmdt(mymsg);
}