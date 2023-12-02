#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

union semun {
int val; /* for SETVAL */
struct semid_ds *buf; /* for IPC_STAT and IPC_SET */
unsigned short *array; /* for GETALL and SETALL */
};

struct SharedMemory
{
	int string[5];
	int in;
	int out;
};

int main()
{
	
	int dataSize = 5;

	key_t mutex, empty, full, shmem;
	int mutexId, emptyId, fullId, memId;
	union semun mutSemun, emptySemun, fullSemun;

	if ((mutex = ftok(".", 'M')) == -1 || (empty = ftok(".", 'E')) == -1 || (full = ftok(".", 'F')) == -1 || (shmem = ftok(".", 'S')) == -1)
	{
		perror("ftok Error");
		exit(1);
	}
	
	if ((mutexId = semget(mutex, 1, 0666 | IPC_CREAT)) == -1 || (emptyId = semget(empty, 1, 0666 | IPC_CREAT)) == -1 || (fullId = semget(full, 1, 0666 | IPC_CREAT)) == -1 || (memId = shmget(shmem, sizeof(struct SharedMemory), 0666 | IPC_CREAT)) == -1)
	{
		perror("semget Error");
		exit(1);
	}
	
	struct SharedMemory *memory = (struct SharedMemory *)shmat(memId, (void *)0, 0);


	memory->in = 0;
	memory->out = 0;

	mutSemun.val = 1;  // adjust the value accordingly
	emptySemun.val = 0;
	fullSemun.val = dataSize;

	shmdt(memory);

	if (semctl(mutexId, 0, SETVAL, mutSemun) == -1 || semctl(emptyId, 0, SETVAL, emptySemun) == -1 || semctl(fullId, 0, SETVAL, fullSemun) == -1) {
		perror("semctl Error");
		exit(1);
	}
	return 0;
}
