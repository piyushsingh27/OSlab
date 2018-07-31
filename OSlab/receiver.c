//receiver program

#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 128

struct msgbuf
{
	long mtype;
	char mtext[MAXSIZE];
};

void main()
{
	int msgid;
	key_t key;
	struct msgbuf rbuf;
	size_t bufflen;
	key=1234;
	if((msgid=msgget(key,0666))<0)
		printf("Error\n");
	if(msgrcv(msgid,&rbuf,MAXSIZE,1,0)<0)
	{
		printf("Error\n");
	}
	else
		printf("%s\n",rbuf.mtext);
	exit(0);
}

