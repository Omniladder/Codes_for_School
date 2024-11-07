#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct sharedMemory
{
	int num1, num2;
	int set;
};

int main()
{
	key_t key;
	if((key = ftok(".", 'x')) == -1)
	{
		printf("FTOK Failed::\n");
		exit(-1);
	}

	int memId;

	if((memId = shmget(key, sizeof(struct sharedMemory), 0666 | IPC_CREAT)) == -1) //Remember struct
	{
		printf("SHGET FAILED::\n");
		exit(-1);
	}


	struct sharedMemory *memory = (struct sharedMemory *)shmat(memId, (void *)0, 0);

	if(memory == (struct SharedMemory *)(-1))
	{
		perror("Memory filed to create");
		exit(-1);
	}

	memory->set = 0;
}
