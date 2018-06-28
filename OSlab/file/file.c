#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
//#include<file.h>
//#include<conio.h>
int main()
{
int ch,fd1;
char txt[60];
char txt1[60];
do
{
printf("\n\t\tFile Menu Operation\n");
printf("\t\t1. File Creation and write \n");
printf("\t\t2. File Reading\n");
printf("\t\t0. Exit \n");
printf("\t\t Enter your choice \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
fd1=open("stu.txt",O_CREAT | O_WRONLY | O_TRUNC);
printf("File created\n");
printf("Input Data:\n");
//scanf("%s",txt);
getchar();
fgets(txt,60,stdin);
write(fd1,txt,strlen(txt));
printf("SUCCESS!\n");
close(fd1);
break;
case 2:
printf("Input File Name:\n");
scanf("%s",txt1);
fd1=open(txt1,O_RDONLY);
fflush(0);
while(read(fd1,txt1,60)>0)
{
write(STDOUT_FILENO,txt1,strlen(txt1));
}
close(fd1);
break;
case 0:
exit(0);
default:

printf("Invalid Choice!");
break;
}
}while(ch!=0);
}

