#ifndef _SEM_DEFINE_H_
#define _SEM_DEFINE_H_

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define KEY_PATH "msg"
#define PROJECT_ID 123
#define MAX_BUFF 80
#define SEMAPHORE_WRITE "/MY_SEM_W"
#define SEMAPHORE_READ "/MY_SEM_R"

static char *message ;
static int shm_id;
static sem_t *write_sem , *read_sem;
#endif
