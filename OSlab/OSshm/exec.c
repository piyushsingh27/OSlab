#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

int main()
{ 
    printf("In Program start\n");
    char *argv[] = {"ls",NULL};
    //execlp("./lss","lss",NULL);
    execl("lss","lss",NULL);
    printf("In Program end\n");
}