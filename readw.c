#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include<stdlib.h>

int main()
{
    int x = mkfifo("abc.txt",0744);
    if( -1 == x )
    {
        if( errno = EEXIST )
        {
            printf("File Exist\n");
        }
        else
        {
            printf("mkfifo failed\n");
            exit(0);
        }
    }

    char str[80];
    while( 1 )
    {
        x = open("abc.txt",O_WRONLY);
        if ( -1 == x )
        {
            printf("File Open Failed\n");
            exit(0);
        }
    }
    int x = write(STDOUT_FILENO,str,80);
    printf("%d\n",x);
}