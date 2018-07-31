// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h> 

int main()
{
    int fd1;
 
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
 
    char str1[80], str2[80];
    //char * str1;
  
        // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1,80);
        //str2 = str1;
        close(fd1);
        size_t ln = strlen(str1) - 1;
		if (*str1 && str1[ln] == '\n') 
    		str1[ln] = '\0';
        fd1 = open(str1,O_RDONLY);
        //printf("%d",fd1);   
        if( - 1 == fd1)
        {
            perror("program");
        }
        int fd2 = open(myfifo,O_WRONLY);
        while( read(fd1,str2,1) > 0)
        {
          printf("%s\n",str2);
            write(fd2,str2,1);
        }
        close(fd1);
        close(fd2);
 
        // Now open in write mode and write
        // string taken from user.
        // fd1 = open(myfifo,O_WRONLY);
        // fgets(str2, 80, stdin);
        // write(fd1, str2, strlen(str2)+1);
        // close(fd1);
    
    return 0;
}