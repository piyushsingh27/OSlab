#include<stdio.h>
#include<fcntl.h>
#include<semaphore.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>  

int main()
{
    sem_t *s1, *s2;
    char *semname1 = "Semaphore5";
    char *semname2 = "Semaphore6";
    char *file = "xyz.txt";

    int fd = open(file, O_CREAT|O_APPEND|O_WRONLY, 0644);

    s1 = sem_open(semname1,O_CREAT, 0644, 1);

    s2 = sem_open(semname2,O_CREAT, 0644, 0);

    sem_wait(s1);
    write(fd, "Child\n",strlen("Child\n"));
    sem_post(s2);
    sem_close(s1);
    sem_close(s2);

    return 0;
}