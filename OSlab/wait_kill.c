#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>

int g_val = 100;

int main()
{
    int x = 10;
    char *name = NULL;
    pid_t PID,PPID;
    int num;

    PID = fork();
    if(PID < 0)
    {
       printf("fork failed");
       exit(0);
    }


    if(PID == 0)//child1
    {
       name = "Child";
	printf("%s   %d   %d", name, x, g_val);
    int n, i, flag = 0;

    printf("Enter a positive integer: ");
    scanf("%d",&n);

    for(i=2; i<=n/2; ++i)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
        printf("%d is a prime number.",n);
    else
        printf("%d is not a prime number.",n);
    
    return 0;
    printf("\n");
    //sleep(5);
       // kill(PPID,9);
        exit(0);
        
    }

    else
    {
        wait(NULL);
	    name = "Parent";
	    //x = x + 10;
	    //g_val = g_val + 100;
	    printf("%s   %d   %d", name, x, g_val);
        printf("\n Enter the number to find factorial:");
        scanf("%d",&num);
        PPID = getpid();
        printf("%d",PPID);
        int i,fact=1;
        for(i = 1;i <= num;i += 1)
        {
            fact = fact * i;
        }
        printf("\n Factorial of number %d is: %d",num,fact);
    }
	//printf("%s   %d   %d", name, x, g_val);
        kill(PPID,9);
        return 0;
}	
        

