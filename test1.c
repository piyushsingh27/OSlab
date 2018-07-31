#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int g_val = 100;

int main(){
    int x = 10;
    char *name = NULL;
    pid_t PID;
    pid_t PIDD;
    PID = fork();
    if(PID < 0){
        printf("FORK Failed");
        exit(0);
    }
    if(PID == 0)
    {
        pid_t PPID;
        PPID = fork();
        if(PPID < 0){
            printf("FORK Failed");
            exit(0);
        }

        if(PPID == 0) /* Child1 */
        {//grandchild1
           char* arg[3] ;//= {"ls",NULL};
        arg[0] = "ls";
        arg[1] = NULL;
        name = "Grandchild1";
        printf("%s %d %d\n",name,x, g_val);
        printf("MY PID is %d\n", getpid());
        printf("MY Parent PID is %d\n", getppid());
        int x = execve("/bin/ls", arg , NULL);
        printf("Num : %d",x);
        } 
        
       
        char* arg[3] ;//= {"ls",NULL};
        arg[0] = "ls";
        arg[1] = NULL;
        name = "Child1";
        printf("%s %d %d\n",name,x, g_val);
        printf("MY PID is %d\n", getpid());
        printf("MY Parent PID is %d\n", getppid());
        int x = execve("/bin/ls", arg , NULL);
        printf("Num : %d",x);

       
        //exit(0);
    }

     PIDD = fork();
    if(PIDD < 0){
        printf("FORK Failed");
        exit(0);
    }
    if(PIDD == 0)
    { //child2

        pid_t PPIDD;
        PPIDD = fork();
        if(PPIDD < 0){
            printf("FORK Failed");
            exit(0);
        }

        if(PPIDD == 0)
        {//grandchild2
           char* arg[3] ;//= {"ls",NULL};
        arg[0] = "ls";
        arg[1] = NULL;
        name = "Grandchild2";
        printf("%s %d %d\n",name,x, g_val);
        printf("MY PID is %d\n", getpid());
        printf("MY Parent PID is %d\n", getppid());
        int x = execve("/bin/ls", arg , NULL);
        printf("Num : %d",x);
        }
         char* arg[3] ;//= {"ls",NULL};
        arg[0] = "ls";
        arg[1] = NULL;
        name = "Child2";
        printf("%s %d %d\n",name,x, g_val);
        printf("MY PID is %d\n", getpid());
        printf("MY Parent PID is %d\n", getppid());
        int x = execve("/bin/ls", arg , NULL);
        printf("Num : %d",x);

        
        //exit(0);
    }
    else { /* Parent */
        name = "Parent";
        x = x + 10;
        g_val = g_val + 100;
        printf("%s %d %d\n",name,x, g_val);
        printf("MY PID is %d\n", getpid());
        printf("MY Child PID is %d\n", PID);
    }
        printf("%s %d %d\n",name,x, g_val);
        return 0;
}