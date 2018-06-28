#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_SIZE 20

int myread(char *str);

 int main()
 {
     char *file_name;
     int ch , len;
     file_name = (char *)malloc(20*sizeof(char));
     if( NULL == file_name )
     {
         write( STDOUT_FILENO , "Malloc Failed" , 14 );
         exit(0);
     }
     write( STDOUT_FILENO , "Enter file Name : " , 19 );
     myread(file_name);
     int x;
     char str[100];
     do
     {
         //system("clear");
         printf("1.Create\n");
         printf("2.Write\n");
         printf("3.Trunc\n");
         printf("4.Append\n");
         printf("5.Read\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
             
                ch = open(file_name,O_CREAT,0744);
                if( ch == -1 )
                {
                    perror("Program");
                    exit(0);                                                                                
                }
                printf("File Creation Succeeded ");
                close(ch);                                                                                     
             break;
                case 2:
                    ch = open(file_name,O_WRONLY,0744);
                    if(-1 == ch)
                    {
                        perror("Program");
                        exit(0);                        
                    }
                    
                    getchar();
                    printf("Check");
                    myread(str);
                    
                    write( STDOUT_FILENO , str , len);
                    x = write(ch,str,strlen(str));

                    if(-1 == x)
                    {
                        perror("Program");
                        exit(0);
                    }
                    close(ch);                                        
                break;

                case 3:
                    ch = open(file_name,O_TRUNC,0744);
                    if( ch == -1 )
                    {
                        perror("Program");
                        exit(0);
                    }
                    printf("File Truncation Succeeded ");
                    close(ch);    
                break;
                
                case 4:
                    ch = open(file_name,O_APPEND,0744);
                    if(-1 == ch)
                    {
                        perror("Program");
                        exit(0);                        
                    }
                    
                    myread(str);
                    x = write(ch,str,strlen(str));
                    if(-1 == x)
                    {
                        perror("Program");
                        exit(0);
                    }
                    close(ch);
                break;


                case 5:
                    ch = open(file_name,O_RDONLY,0744);
                    if(-1 == ch)
                    {
                        perror("Program");
                        exit(0);                        
                    }
                    
                    
                     x = read(ch,str,100);
                    if(-1 == x)
                    {
                        perror("Program");
                        exit(0);
                    }
                    printf("%d",ch);
                    close(ch);
                break;                                
         }

     } while(ch!=6);
     
     return 0;
 }

int myread(char *str)
{
    int ch;
    ch = read( STDIN_FILENO , str , FILE_SIZE );
     if( -1 == ch )
     {
         write( STDOUT_FILENO , "Reading File Name Failed : " , 25);
         exit(0);
     }    
    int len = strlen(str);
     if( str[len - 1] == '\n' || str[len - 1] == '\r' )
     {
         str[len - 1] = '\0';
     }
}