/*Write a program hellomany.c that will create a number N of threads specified in the command line, each of which prints out a hello message and its own thread ID. To see how the execution of the threads interleaves, make the main thread sleep for 1 second for every 4 or 5 threads it creates. The output of your code should be similar to:
       I am thread 1. Created new thread (4) in iteration 0...
       Hello from thread 4 - I was created in iteration 0
       I am thread 1. Created new thread (6) in iteration 1...
       I am thread 1. Created new thread (7) in iteration 2...
       I am thread 1. Created new thread (8) in iteration 3...
       I am thread 1. Created new thread (9) in iteration 4...
       I am thread 1. Created new thread (10) in iteration 5...
       Hello from thread 6 - I was created in iteration 1
       Hello from thread 7 - I was created in iteration 2
       Hello from thread 8 - I was created in iteration 3
       Hello from thread 9 - I was created in iteration 4
       Hello from thread 10 - I was created in iteration 5
       I am thread 1. Created new thread (11) in iteration 6...
       I am thread 1. Created new thread (12) in iteration 7...
       Hello from thread 11 - I was created in iteration 6
       Hello from thread 12 - I was created in iteration 7
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 50

pthread_t thread_id[MAX_THREADS];    

void * PrintHello(void * data)
{
    printf("Hello from thread %u - I was created in iteration %d !\n", (int)pthread_self(), (int)data);
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
    int rc, i, n;

    if(argc < 2) 
    {
        printf("Please add the number of threads to the command line\n");
        exit(1); 
    }
    n = atoi(argv[1]);
    if(n > MAX_THREADS) n = MAX_THREADS;

    for(i = 0; i < n; i++)
    {
        rc = pthread_create(&thread_id[i], NULL, PrintHello, (void*)i);
        if(rc)
        {
             printf("\n ERROR: return code from pthread_create is %d \n", rc);
             exit(1);
        }
        printf("\n I am thread %u. Created new thread (%u) in iteration %d ...\n", 
                (int)pthread_self(), (int)thread_id[i], i);
        if(i % 5 == 0) sleep(1);
    }

    pthread_exit(NULL);
}
