/************************************************************************************
 Program to demonstrate use of named semaphores between two unrelated processes
*************************************************************************************/

#include "sem_define.h"

static void sig_usr(int );

int main()
{
    signal(SIGINT , sig_usr);
    key_t fkey = ftok( KEY_PATH , PROJECT_ID );
    
    if( -1 == fkey )
    {
        perror("FTOK failed");
        exit(1);
    }

    shm_id = shmget(fkey , MAX_BUFF , 0644 | IPC_CREAT);
    if( -1 == shm_id )
    {
        perror("SHM get failed");
        exit(1);
    }

    write_sem = sem_open(SEMAPHORE_WRITE , O_CREAT , 0644 , 1);
    if( NULL == write_sem )
    {
        perror("Opening write Semaphore failed");
        exit(1);
    }

    read_sem = sem_open(SEMAPHORE_READ , O_CREAT , 0644 , 0);
    if( NULL == read_sem )
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
        printf("Enter message : ");
        scanf("%s",message);
        sem_wait(write_sem);
        /*Critical Section*/
        memcpy(message , message , 10);
        /*End of Crirical Section*/
        sem_post(read_sem);
    }
}

static void sig_usr(int signal)
{
    struct shmid_ds myds;
    shmctl(shm_id , IPC_STAT , &myds);
    printf("\n\nNo of processes attached : %d\n\n" , myds.shm_nattch);
    printf("Disconnecting client %d\n\n" , myds.shm_lpid);
    shmdt(message);
    printf("Removing Shared Memory Object\n\n");
    shmctl(shm_id , IPC_RMID , NULL);
    printf("Closing Semaphore Objects\n\n");
    sem_close(read_sem);
    sem_close(write_sem);
    printf("Removing Semaphore Objects\n\n");
    sem_unlink(SEMAPHORE_READ);
    sem_unlink(SEMAPHORE_WRITE);
    exit(0);
}