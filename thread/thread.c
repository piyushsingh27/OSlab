//Program to implement POSIX Threads
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *p();

int main()
{
	pthread_t tid;
	int d;
	void *y;
	d=pthread_create(&tid,NULL,p,NULL);
	if(d != 0)
	{
		printf("Thread is not created\n");
	}
	sleep(5);
	
	d = pthread_cancel(tid);
	
	if(d != 0)
	{
		printf("Not able to cancel the thread\n");
	}
	
	printf("Waiting for thread to get closed\n");

	d=pthread_join(tid,&y);

	if(d != 0)
	{
		printf("Invalid\n");
	}
}

void *p()
{
	int r,i;
	//r=pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	printf("Main Thread\n");

	for(i=0;i<=4;i++)
	{
		printf("Inside thread (%d) \n",i);
		sleep(1);
	}

pthread_exit(0);
}
