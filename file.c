#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
	int fd, sz;
	char *c;
	int fd1, sz1 = 1;
	
	fd1 = open("Sample.txt", O_RDONLY);

	c = (char *) calloc(20, sizeof(char));
	
	if(fd1 < 0)
	{
		perror("file : "); 
		exit(0);
	}
	
	
	while(sz1 > 0)
	{
		sz1 = read(fd1, c,20);
		printf("initial twenty bytes:\n");
		printf("%s", c);
		printf("\n final twenty bytes:\n");
		sz = read(fd1, c, 20);
		printf("%s",c);
		exit(1);
		
	}
	
	
	close(fd1);
	//close(fd);
}
