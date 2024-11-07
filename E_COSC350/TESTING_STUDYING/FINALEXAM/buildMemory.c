#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>


struct sharedMemory{
	int dataArray[5];
};

union semun {
	int val; //for SETVAL
	struct semid_ds *buf; //for IPC_STAT and IPC_SET
	unsigned short *array; //for GETALL and SETALL
};



int main()
{
	key_t semKey, memKey;
	int semId, memId;

	if((memKey = ftok(".", 'M')) == -1)
	{
		perror("Shared Memory Key failed to build");
		exit(-1);
	}

	if((semKey = ftok(".", 'S')) == -1)
	{
		perror("Semaphore key Failed to build");
		exit(-1);
	}

	if((semId = semget(semKey, 3, 0666 | IPC_CREAT)) == -1) //One for mutex one for empty one for full
	{
		perror("Failed To make semaphore ID");
		exit(-1);
	}

	if((memId = shmget(memKey, sizeof(struct sharedMemory), 0666 | IPC_CREAT)) == -1)
	{
		perror("Failed to make Memory Id");
		exit(-1);
	}

	struct sharedMemory* memory;

	memory = (struct sharedMemory *)shmat(memId, NULL, 0);


	union semun mutexSet;
	union semun emptySet;
	union semun fullSet;

	mutexSet.val = 1;
	emptySet.val = 5;
	fullSet.val = 0;
	
	semctl(semId, 0, SETVAL, mutexSet);
	semctl(semId, 1, SETVAL, emptySet);
	semctl(semId, 2, SETVAL, fullSet);


	shmdt(memId); //I bet he'll dock for missing this
}
