#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MESSAGE 16
char *msg1 = "First Message";
char *msg2 = "Second Message";
char *msg3 = "Third Message";

int main()
{
    char str[MESSAGE];
    int p[2],pid,n;

    if(pipe(p) < 0)
    {
        exit(1);
    }

    if((pid = fork()) > 0)
    {
        write(p[1],msg1,MESSAGE);
        write(p[1],msg2,MESSAGE);
        write(p[1],msg3,MESSAGE);

        close(p[1]);
        wait(NULL);
    }

    else{
        close(p[1]);
        while((n = read(p[0],str,MESSAGE)) > 0)
        printf("%s \n",str);

        //if(nbytes != 0)
        //exit(2);

        printf("\n Finished reading");
        }
    return 0;
}
