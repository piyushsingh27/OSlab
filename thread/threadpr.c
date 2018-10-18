#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *p();

int main()
{
    pthread_t tid;
    int d;
    void *y;

    d = pthread_create(&tid, NULL, p, NULL);
    if(d != 0)
    {
        printf("thread not created");
        exit(0);
    }
    sleep(5);

    d = pthread_join(tid, &y);
}

void *p()
{
    int i;
    sleep(1);
    printf("Main Thread \n");

    for(i = 0; i < 5; i += 1)
    {
        sleep(1);
        printf("%d \n",i);
        sleep(1);
    }
    pthread_exit(0);
}