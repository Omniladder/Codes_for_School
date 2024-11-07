#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	key_t key;
	int memoryID;
	
	key = ftok("key", 'A');
	
	if((memoryID = shmget(key, sizeof(struct Memory), 0)) < 0)
	{
		perror("shmget error\n");
		exit(1);
	}
	
	shmctl(memoryID, IPC_RMID, NULL);
	return 0;
}
