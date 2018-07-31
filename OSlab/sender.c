//sender program

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
	int msgflag=IPC_CREAT|0666;
	key_t key;
	struct msgbuf sbuf;
	size_t bufflen;
	key=1234;
	if((msgid=msgget(key,msgflag))<0)
		printf("Error\n");
	else
		sbuf.mtype=1;
	printf("Enter the text into message queue\n");
	scanf("%s",sbuf.mtext);
//	gets(sbuf.mtext);
	bufflen=strlen(sbuf.mtext)+1;
	if(msgsnd(msgid,&sbuf,bufflen,IPC_NOWAIT)<0)
		printf("Error\n");
	else
		printf("Message Sent\n");
	exit(0);
}

