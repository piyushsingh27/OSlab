#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include<sys/stat.h>

int main()
{
    int res = mkfifo("myfifo",0644);
    if( -1 == res )
    {
        if( errno == EEXIST )
        {
            printf("Fifo already exists \n");
        }
        else
        {
            printf("Fifo creation failed \n");
            exit(0);
        }
    }

    int fd = open("myfifo",O_WRONLY);
    printf("Opened Client\n");
    //write(fd,"hello from client",18);
}