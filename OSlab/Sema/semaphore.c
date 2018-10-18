#include <fcntl.h>
#include <unistd.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<stdlib.h>
#include <string.h>
#include<stdio.h>


int main(int argc, char const *argv[])
{
    char * semname1 = "/SemFile";
    char * semname2 = "/SemFile1";
    char * fileName = "abc.txt";
    sem_t *s1 ,*s2;
    pid_t p ;
    int count = 3,retVal;
    int fd = open(fileName,O_CREAT|O_APPEND|O_WRONLY,0644);
    if(fd < 0)
    {
        perror("File Opening Error");
        exit(EXIT_FAILURE);
    }
    s1 = sem_open(semname1,O_CREAT,0644,1);
    if(s1 == SEM_FAILED)
    {
        perror("Semaphore not created:");
        exit(0);
    }
    
    s2 = sem_open(semname2,O_CREAT,0644,0);
     if(s2 == SEM_FAILED)
    {
        perror("Semaphore not created:");
        exit(0);
    } 


    sem_wait(s2);
    write(fd,"PareDnt\n",strlen("PaDrent\n"));
    sem_post(s1);
    sem_close(s1);
    sem_close(s2);
  /* sem_unlink(semname1);
   sem_unlink(semname2);*/

    return 0;
}

