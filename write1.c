#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
    int x = mkfifo("abc.txt",0744);
    if(-1 == x)
    {
        if(errno == EEXIST)
        printf("Already exist \n");

        else{
            printf("mkfifo failed \n");
            exit(0);
        }
    }

    char str[80];
    int z;
    str[0] = '\0';

    while(1)
    {
        int x = open("abc.txt",O_WRONLY);
        if(-1 == x)
        {
            printf("file open failed");
            exit(0);
        }

        write(1,"Enter message: \n",15);
        while(read(0,str,1) > 0)
        {
            z = write(x,str,1);
        }
        printf("write: %d",z);
        close(x);

    }
    return 0;
}