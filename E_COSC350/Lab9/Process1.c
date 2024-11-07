#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <errno.h>
#include <unistd.h>
#include "header.h"

int main()
{
	int memID;
	key_t key;
	
	struct Memory *memory;
	
	int n, n2;
	key=ftok("key", 'A');
	
	if((memID = shmget(key, sizeof(struct Memory), 0))<0)
	{
		perror("shmget error \n");
		exit(1);
	}
	
	memory = (struct Memory *) shmat(memID, NULL, 0);
	
	if((long)memory == -1)
	{
		perror("shmat error \n");
		exit(1);
	}
	
	memory->gostop = GO;
	memory->status = NOT_READY;

	char buffer[BUFSIZ+1];
	memset(buffer, '\0', sizeof(buffer));
	
	printf("Enter two integers: \n");
	
	while(read(0, buffer, BUFSIZ) > 0){
		if(sscanf(buffer, "%d%d", &n, &n2) == 2){
			memory->data.int1 = n;
			memory->data.int2 = n2;
			memory->status = FILLED;
			
			while(memory->status != TAKEN);
			printf("Enter two integers: \n");
		}
		else{
			printf("Invalid integers\n Enter two integers:\n");
		}
	}
	
	memory->gostop = STOP;
	shmdt((void *) memory);
	return 0;
}
