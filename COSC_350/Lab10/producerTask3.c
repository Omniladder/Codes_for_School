#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

void down(int semid)
{
struct sembuf buf = {0, -1, 0};
semop(semid, &buf, 1);
}

void up(int semid)
{
struct sembuf buf = {0, 1, 0};
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
	int mutexId, emptyId, fullId, shMemId;



	if ((mutex = ftok(".", 'M')) == -1 || (empty = ftok(".", 'E')) == -1 || (full = ftok(".", 'F')) == -1 || (shMem = ftok(".", 'S')))
	{
		perror("ftok Error");
		exit(1);
	}
	
	if ((mutexId = semget(mutex, 1, 0666)) == -1 || (emptyId = semget(empty, 1, 0666)) == -1 || (fullId = semget(full, 1, 0666)) == -1 || (shMemId = shmget(shMem, sizeof(struct SharedMemory), 0666)) == -1)
	{
		perror("semget Error");
		exit(1);
	}

	int consumedData;


	struct SharedMemory *memory = (struct SharedMemory *)shmat(shMemId, (void *)0, 0);

	while(1)
	{
		down(fullId);
		down(mutexId);
	
		consumedData = rand() % 10 + 1;
		memory->string[memory->out] = consumedData;
		memory->out = (memory->out + 1) % dataSize;
		
		up(mutexId);
		up(emptyId);

		outputMemory(memory);

		printf("PRODUCED ADDED :: %d\n", consumedData);
	}
	
}
