#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>    
#include<semaphore.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
    sem_t *s1, *s2;
    char *semname1 = "/SemFile3";
    char *semname2 = "/SemFile4";
    char *file = "abcd.txt";

    int fd = open(file, O_CREAT|O_APPEND|O_WRONLY,0644);
    if(fd < 0)
    {
        printf("File open failed");
        exit(0);
    }

    s1 = sem_open(semname1, O_CREAT, 0644, 1);
    if(s1 == SEM_FAILED)
    {
        printf("semaphore open error");
        exit(0);
    }

    s2 = sem_open(semname2, O_CREAT, 0644, 0);
    if(s2 == SEM_FAILED)
    {
        printf("semaphore open error");
        exit(0);
    }



    sem_wait(s2);
    write(fd,"Child \n", strlen("Child \n"));
    sem_post(s1);
    sem_close(s1);
    sem_close(s2);


    return 0;
}