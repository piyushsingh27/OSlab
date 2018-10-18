#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *myfun()
{
    static int x = 10;
    for( int i = 0 ; i < 10 ; i++ )
    {
        printf("Thread 1 : %d\n",i);
        sleep(1);
    }
    return (void *)&x;
}

void *myfun2()
{
    static int x = 10;
    for( int i = 0 ; i < 10 ; i++ )
    {
        printf("Thread 2 : %d\n",i);
        sleep(1);
    }
    return (void *)&x;
}

int main()
{
    pthread_t th,th2;
    pthread_attr_t attr;
    int *threadout;
    int *threadout2;
    pthread_attr_init(&attr);
    pthread_create(&th,&attr,myfun,(void *)NULL);
    pthread_create(&th2,&attr,myfun2,(void *)NULL);
    pthread_join(th,(void **)&threadout);
    pthread_join(th2,(void **)&threadout2);
    printf("End of program\n");
}
