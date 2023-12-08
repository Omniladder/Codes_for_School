#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


struct SharedMemory
{
	int string[5];
	int count; 
};

int main()
{
	key_t key = ftok(".", -937700319);

	if(key == -1)
	{
		perror("Key Failed");
		exit(-1);
	}

	int memoryId = shmget(key, sizeof(struct SharedMemory), 0666 | IPC_CREAT);


	if(memoryId == -1)
	{
		perror("ID Failed");
		exit(-1);
	}


	struct SharedMemory *memory = (struct SharedMemory *)shmat(memoryId, (void *)0, 0);

	if(memory == (struct SharedMemory *)(-1))
	{
		perror("Memory filed to create");
		exit(-1);
	}
	
	memory->count = 0;

	shmdt(memory);

	return 0;
}
