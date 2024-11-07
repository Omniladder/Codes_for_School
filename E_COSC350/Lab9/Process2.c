#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include "header.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	key_t key;
	int memoryID;
	
	struct Memory *memory;
	key = ftok("key",'A');
	
	if((memoryID = shmget(key, sizeof(struct Memory), 0)) < 0)
	{
		perror("shmget error \n");
		exit (1);
	}
	
	memory = (struct Memory *) shmat(memoryID, NULL, 0);
	
	if((long) memory == -1)
	{
		perror("shmat error\n");
		exit(1);
	}

	while (memory->gostop == GO && memory->gostop != STOP)
	{
		while(memory->status != FILLED)
		{
			if(memory->gostop == STOP)
				break;
		}
		printf("Sum of the two integer: %d\n", memory->data.int1 + memory->data.int2);
		memory->status = TAKEN;
	}
	shmdt((void*)memory); 
	return 0;
}
