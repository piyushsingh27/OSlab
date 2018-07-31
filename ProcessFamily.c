#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COUNT 10

void Parent_Process(void);

void Child_Process(void);
void Child_2_Process(void);
void Grand_Child_Process(void);
void Grand_Child_2_Process(void);


void main()
{
	pid_t pid, pid2; 
	pid = fork();
	pid2 = fork();
	
	if(pid == 0) 
		Child_Process();
	else if(pid2 == 0)
		Child_2_Process();
	else
		Parent_Process();
	_exit(EXIT_SUCCESS);

}

void Parent_Process()
{
	pid_t p;
	p = getpid();
	printf("\nI am the PARENT. My PID is %d \n", p);
	
}

void Child_Process(void)
{
	int i;
	pid_t gpid, ggpid;
	//pid = getpid();
	ggpid = fork();
	printf("\nI am the 1st CHILD. My PID is %d \n", getpid());
	if(ggpid == 0)
		Grand_Child_Process();
	else 
		Child_2_Process();
}

void Child_2_Process(void)
{
	int i, num, flag =0;
	pid_t pid, gpid2;
	pid = getpid();
	gpid2 = fork();
	printf("\nI am the 2nd CHILD. My PID is %d \n", getpid());

	if(gpid2 == 0)
		Grand_Child_2_Process();
	else
		exit(6);

}

void Grand_Child_Process()
{
	printf("\nI am the GRAND CHILD of the Original Process. My PID is %d \n", getpid());
	_exit(EXIT_SUCCESS);
	
}


void Grand_Child_2_Process()
{
	printf("\nI am the 2nd GRAND CHILD of the Original Process. My PID is %d \n", getpid());
	_exit(EXIT_SUCCESS);
}

