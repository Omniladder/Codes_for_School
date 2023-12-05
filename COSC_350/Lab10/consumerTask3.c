#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

void down(int semid, int index)
{
struct sembuf buf = {index, -1, 0};
semop(semid, &buf, 1);
}

void up(int semid, int index)
{
struct sembuf buf = {index, 1, 0};
semop(semid, &buf, 1);
}


struct SharedMemory
{
	int string[5];
	int in;
	int out;
};

void outputMemory(struct SharedMemory*  memory)
{
	printf("[");
	for(int i = 0; i < 5; i++)
	{
		printf(", %d", memory->string[i]);
	}
	printf("]");
}
int main()
{

	int dataSize = 5;

	key_t mutex, empty, full, shMem;
	int semId, shMemId;
	
	int Mutex = 0, Full = 1, Empty = 2;

	if ((mutex = ftok(".", 'M')) == -1 || (shMem = ftok(".", 'S')) == -1)
	{
		perror("ftok Error");
		exit(1);
	}
	
	if ((semId = semget(mutex, 3, 0666)) == -1)
	{
		perror("semget Error");
		exit(1);
	}

	if(shMemId = shmget(shMem, sizeof(struct SharedMemory), 0666) == -1)
	{
		perror("Memory Failed");
		exit(1);
	}

	int consumedData;

	printf("BEFORE SHARED MEMOEry\n");

	struct SharedMemory *memory = (struct SharedMemory *)shmat(shMemId, (void *)0, 0);

	printf("BEFORE THE LOOP\n");

	while(1)
	{
		down(semId, Full);
		down(semId, Mutex);
	
		consumedData = memory->string[memory->out];
		memory->string[memory->out] = 0;
		memory->out = (memory->out + 1) % dataSize;
		
		outputMemory(memory);
		
		up(semId, Mutex);
		up(semId, Empty);


		printf("CONSUMER REMOVED :: %d\n", consumedData);
		
		sleep(1);
	}
	
}
