#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
printf("Hello world\n");
write(STDOUT_FILENO, "Ciao\n", 5);
fork();
//if (fork() == -1)
//xit("fork");
/* Both child and parent continue execution here */
exit(EXIT_SUCCESS);
}