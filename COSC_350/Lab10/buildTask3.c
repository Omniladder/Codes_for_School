#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
union semun {
int val; /* for SETVAL */
struct semid_ds *buf; /* for IPC_STAT and IPC_SET */
unsigned short *array; /* for GETALL and SETALL */
};
int main()
{
	key_t mutex, empty, full;
	int mutexId, emptyId, fullId;
	union semun mutSemun, emptySemun, fullSemun;

	if ((mutex = ftok(".", 'M')) == -1 || (empty = ftok(".", 'E')) == -1 || (full = ftok(".", 'F')) == -1)
	{
		perror("ftok Error");
		exit(1);
	}
	
	if ((mutexId = semget(mutex, 1, 0666 | IPC_CREAT)) == -1 || (emptyId = semget(empty, 1, 0666)) == -1 || (fullId = semget(full, 1, 0666)) == -1)
	{
		perror("semget Error");
		exit(1);
	}
	
	mutSemun.val = 1;
	emptySemun.val = 1;
	fullSemun.val = 1;

	if (semctl(mutexId, 0, SETVAL, mutSemun) == -1 || semctl(emptyId, 0, SETVAL, emptySemun) == -1 || semctl(fullId, 0, SETVAL, fullSemun) == -1) {
		perror("semctl Error");
		exit(1);
	}
	return 0;
}
