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

    
    char str[80] ;
    int z;
    while( 1 )
    {
        str[0] = '\0';
        x = open("abc.txt",O_WRONLY);
        if ( -1 == x )
        {
            printf("File Open Failed\n");
            exit(0);
        }
        write(STDOUT_FILENO,"Enter message : \n",15);
        int len = read(STDIN_FILENO,str,80);
        
        if( str[len - 1] == '\n' || str[len - 1] == '\r' )
        {
            str[len - 1] = '\0';
        }
        z = write(x,str,strlen(str)+1);
        printf("len : %d\nwrite : %d\n",len,z);
        close(x);
        //write(STDOUT_FILENO,str,80);
    }
}