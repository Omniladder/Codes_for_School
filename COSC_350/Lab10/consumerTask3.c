#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
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


int main()
{

	int dataSize = 10;

	key_t mutex, empty, full;
	int mutexId, emptyId, fullId;



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

	struct sembuf semSetter = {0, dataSize, 0};
	semop(emptyId, &semSetter, 1);

	semSetter.sem_num = 0;
	semSetter.sem_op = 0;
	semSetter.sem_flg = 0;
	semop(fullId, &semSetter, 1);

	semSetter.sem_num = 0;
	semSetter.sem_op = 1;
	semSetter.sem_flg = 0;
	semop(mutexId, &semSetter, 1);	


	while(1)
	{
		
	}
	
}
