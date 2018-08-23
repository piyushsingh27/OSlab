/************************************************************************************
 Program to demonstrate use of named semaphores between two unrelated processes
*************************************************************************************/

#include "sem_define.h"



int main()
{
    
    key_t fkey = ftok( KEY_PATH , PROJECT_ID );
    
    if( -1 == fkey )
    {
        perror("FTOK failed");
        exit(1);
    }

    shm_id = shmget(fkey , MAX_BUFF , IPC_CREAT);
    if( -1 == shm_id )
    {
        perror("SHM get failed");
        exit(1);
    }

    write_sem = sem_open(SEMAPHORE_WRITE , O_CREAT );
    if( NULL == sync )
    {
        perror("Opening write Semaphore failed");
        exit(1);
    }

    read_sem = sem_open(SEMAPHORE_READ , O_CREAT );
    if( NULL == sync )
    {
        perror("Opening read Semaphore failed");
        exit(1);
    }

    message = shmat(shm_id , NULL , 0);
    if( NULL == message )
    {
        perror("Shared Memory Attachment Failed");
        exit(1);
    }

    while(1)
    {
        sem_wait(read_sem);
        /*Critical Section*/
        printf("Message : %s \n",message);
        /*End of Crirical Section*/
        sem_post(write_sem);
    }
}