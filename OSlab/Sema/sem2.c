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

    s2 = sem_open(semname2, O_CREAT, 0644, 0);

    sem_wait(s1);
    write(fd,"Parent \n",strlen("Parent \n"));
    sem_post(s2);

    sem_close(s1);
    sem_close(s2);

    return 0;
}