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
        x = open("abc.txt",O_RDONLY);
        if ( -1 == x )
        {
            printf("File Open Failed\n");
            exit(0);
        }
        //lseek(x,0,SEEK_SET);
        int len = read(x,str,80);
        //int len = strlen(str);
        if( str[len - 1] == '\n' || str[len - 1] == '\r' )
        {
            str[len - 1] = '\0';
        }
        write(STDOUT_FILENO,str,strlen(str)+1);
        write(STDOUT_FILENO,"\n",2);
        close(x);
    }
}