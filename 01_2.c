#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int fd = -1,check = 0;
    char ww[51];
    fd = open("sample.txt",O_CREAT|O_RDONLY,0766);
    if(fd == -1)
    {
        printf("File Opening Error");
    }
     printf("\n Initial 20 bytes");
    check = read(fd,ww,20);

  // printf("%d",check);
   
    write(1,ww,19);
    write(1,"\n",1);
    lseek(fd,10,SEEK_CUR);

    printf("\n Final 20 bytes");
    check = read(fd,ww,20);

    //
    write(1,ww,20);
}
