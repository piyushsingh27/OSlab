#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int g_val = 100;

int main()
{
    int x = 10;
    char *name = NULL;
    pid_t PID;

    PID = fork();
    if(PID < 0)
    {
       printf("fork failed");
       exit(0);
    }


    if(PID == 0)
    {
       name = "Child";
	printf("%s   %d   %d", name, x, g_val);
        //exit(0);
    }

    else
    {
	name = "Parent";
	x = x + 10;
	g_val = g_val + 100;
	printf("%s   %d   %d", name, x, g_val);
    }
	printf("%s   %d   %d", name, x, g_val);
        return 0;
}	
        
