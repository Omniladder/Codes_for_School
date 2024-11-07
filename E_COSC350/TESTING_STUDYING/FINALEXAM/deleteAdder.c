#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

struct sharedMemory
{
	int num1, num2;
};

int main()
{
	key_t semaKey, memKey;
	int semaId, shmId;
	if((shmId = ftok(".", 'M')) == -1 || (semaId = ftok(".", 'S')) == -1)
	{
		perror("Getting Key Weird");
		exit(-1);
	}

	if((shmId = shmget(shmId, sizeof(struct sharedMemory), 0666)) == -1)
	{
		perror("Failed to make Memory Id");
		exit(-1);
	}

	if(shmctl(shmId, IPC_RMID, NULL) == -1)
	{
		perror("Failed to Delete Memory");
		exit(-1);
	}

	if((semaId = semget(semaId, 2, 0666)) == -1)
	{
		perror("Failed to make Sema ID");
		exit(-1);
	}

	if(semctl(semaId, IPC_RMID, NULL) == -1)
	{
		perror("Failed to Delete Semaphore");
		exit(-1);
	}

	return 0;
}
