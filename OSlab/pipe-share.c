// C program to illustrate
// pipe system call in C
// shared by Parent and Child
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>

#define MSGSIZE 16
char* msg1 = "First message";
char* msg2 = "Second message";
char* msg3 = "Third message";
 
int main()
{
    char str[MSGSIZE];
    int p[2], pid, nbytes;
 
    if (pipe(p) < 0)
        exit(1);
 
    /* continued */
    if ((pid = fork()) > 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
 
        // Adding this line will
        // not hang the program
         //close(p[1]);
        wait(NULL);
    }
 
    else {
        // Adding this line wills
        // not hang the program
        //close(p[1]);
        while ((nbytes = read(p[0], str, MSGSIZE)) > 0)
            printf("%s\n", str);
        if (nbytes != 0)
            exit(2);
        printf("Finished reading\n");
    }
    return 0;
}
