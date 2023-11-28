#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include "header.h"

int main(int argc, char **argv)
{
	int memoryID;
	key_t key;
	struct Memory *memory;
	key = ftok("key", 'A'); 
	if((memoryID=shmget(key, sizeof(struct Memory), IPC_CREAT | 0666)) < 0)
	{
		perror("shmget error\n");
		exit(1);
	}
	memory = (struct Memory *)shmat(memoryID, NULL, 0);
	if((long)memory == -1){
		perror("shmat error \n");
		exit(1);
	}
	memory->status = NOT_READY;
	memory->gostop = GO;
	return 0;
}
