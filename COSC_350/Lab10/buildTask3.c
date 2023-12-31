#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

//Union for semaphore operations
union semun {
	int val; //for SETVAL
	struct semid_ds *buf; //for IPC_STAT and IPC_SET
	unsigned short *array; //for GETALL and SETALL
};

//Struct for shared mem.
struct SharedMemory
{
	int string[5];
};

int main()
{
	//# of elements in shared mem. buffer
	int dataSize = 5;

	//Semaphore and shared mem. key variables
	key_t mutex, empty, full, shmem;
	int Mutex = 0, Full = 1, Empty = 2;
	int mutexId, emptyId, fullId, memId;
	union semun mutSemun, emptySemun, fullSemun;

	//Generate unique keys for semaphores and shared mem.
	if ((mutex = ftok(".", 'M')) == -1 || (shmem = ftok(".", 'S')) == -1)
	{
		perror("ftok Error");
		exit(1);
	}
	
	//Create or get IDs for semaphores and shared mem.
	if ((mutexId = semget(mutex, 3, 0666 | IPC_CREAT)) == -1)
	{
		perror("semget Error");
		exit(1);
	}
	
	// Create or get ID for shared memory
	if ((memId = shmget(shmem, sizeof(struct SharedMemory), 0666 | IPC_CREAT)) == -1) {
        	perror("shmget Error");
		exit(1);
	}
	
	//Attach the shared mem. segment to the address space of the calling process
	struct SharedMemory *memory = (struct SharedMemory *)shmat(memId, (void *)0, 0);

	//Initialize shared mem. variables

	//Set initial values for semaphores
	mutSemun.val = 1;  //Mutex semaphore, allowing one process to access the shared memory at a time
	fullSemun.val = 0; //Semaphore indicating empty slots in the buffer
	emptySemun.val = dataSize; //Semaphore indicating the number of full slots in the buffer

	//Detach the shared memory segment from the address space of the calling process
	shmdt(memory);

	semctl(mutexId, Full, SETVAL, fullSemun);
	semctl(mutexId, Mutex, SETVAL, mutSemun);
	semctl(mutexId, Empty, SETVAL, emptySemun);
	
	//Set initial values for semaphores using semctl
	/*if (semctl(mutexId, 0, SETVAL, mutSemun) == -1) {
		perror("semctl Error");
		exit(1);
	}*/
	return 0;
}
