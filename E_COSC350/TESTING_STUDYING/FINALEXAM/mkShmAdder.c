#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

union semun {
	int val; //for SETVAL
	struct semid_ds *buf; //for IPC_STAT and IPC_SET
	unsigned short *array; //for GETALL and SETALL
};

struct sharedMemory
{
	int num1, num2;
};

int main()
{
	key_t memoryKey; // you need to set ftok to a key_t
	int memId; //This is to hold the memory it needs an int apparently
	if((memoryKey = ftok(".", 'M')) == -1)
	{
		printf("Memory Key Failed to Make\n");
		exit(-1);
	}


	if((memId = shmget(memoryKey, sizeof(struct sharedMemory), 0666 | IPC_CREAT)) == -1) // ftok key size of shared memory and then permissions and create
	{
		printf("Failed to Make Memory");
		exit(-1);
	}

	struct sharedMemory *memory = (struct sharedMemory *)shmat(memId, NULL, 0); //Needs to be a pointer Generally set second parameter to NULL generally you want it to be a pointer to whaere you want it and 0 is for flags like Read only so once again dont care

	memory->num1 = 0;
	memory->num2 = 0;

	shmdt(memory);


	//Shared Memory Code NEATO


	key_t semaKey; // you need to set ftok to a key_t
	int sem; //THIS is to set semaphore
	union semun hasSet;
	union semun hasntSet;
	
	if((semaKey = ftok(".", 'S')) == -1)
	{
		printf("Failed to Make SemaPhore Key\n");
		exit(-1);
	}
	
	if((sem = semget(semaKey, 2, 0666 | IPC_CREAT)) == -1) //1 is number of members
	{
		printf("Failed to make Semaphore \n");
		exit(-1);
	}

	hasSet.val = 0;
	hasntSet.val = 1;

	semctl(sem, 0, SETVAL, hasntSet); //1 is index sem is the semaphore ID SET_VAL is the command sema is what its being set too Doesnt recognize SETVAL
	semctl(sem, 1, SETVAL, hasSet); //0 is index sem is the semaphore ID SET_VAL is the command sema is what its being set too Doesnt recognize SETVAL

	return 0;
}
