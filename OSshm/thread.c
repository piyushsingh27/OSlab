#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define LOOPSZ	8

int t1retval = 2;
int t2retval = 10;

/*
startroutine1 takes an input and prints it after properly typecasting it
*/

void * startroutine1(void * thr_p) 
{
	int i = 0;
	//int pinput = *((int *) thr_p);
	int pinput = thr_p ? *((int *) thr_p) : 0;
	printf("startroutine1  threadid : %lu\n", pthread_self());
	while (i++ < LOOPSZ)
	{
		printf("startroutine1  thread %d %d\n", i, pinput);
		sleep(1);
	}
	return ((void *) &t1retval);
}

/*
startroutine2 prints the thread id and the value of a local variable i in a loop
*/

void * startroutine2(void * thr_p)
{
	int i = 0;
	//int pinput = *((int *) thr_p);
	int pinput = thr_p ? *((int *) thr_p) : 0;
	printf("startroutine2  threadid : %lu\n", pthread_self());
	while (i++ < LOOPSZ) 
	{
		printf("startroutine2 thread %d %d\n", i, pinput);
		sleep(1);
	}
	pthread_exit ((void *) &t2retval);
	return ((void *) &t1retval);
}

/*
main creates two threads and waits for them to exit
one of the threads is passed the address of a local variable defined in main whereas the other one is given a NULL parameter
*/

int main()
{
	int retval;
	int * pthreadoutput;
	int thread1input = 10;
	pthread_t tidOne;
	pthread_t tidTwo;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes
	retval = pthread_create(&tidOne, &atrr, startroutine1, (void *)(&thread1input));
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	printf("%lu\n", tidOne);
	retval = pthread_create(&tidTwo, NULL, startroutine2, (void *)NULL);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	retval = pthread_join(tidOne, (void**)&pthreadoutput);
	printf("threadoutput %d\n", *pthreadoutput);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}
	retval = pthread_join(tidTwo, (void**)&pthreadoutput);
	printf("threadoutput %d\n", *pthreadoutput);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}
	return 0;
}