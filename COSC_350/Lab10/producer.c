#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

struct SharedMemory {
	int string[5];
	int count;
};

void outputMemory(struct SharedMemory* memory)
{
	printf("[");
	for(int i = 0; i < 5; i++)
	{
		printf(", %d", memory->string[i]);
	}
	printf("]\n");
}

int main() {
	key_t key = ftok(".", -937700319);
	int memoryID = shmget(key, sizeof(struct SharedMemory), 0666);

	int dataSize = 5;
	struct SharedMemory *sharedMem = (struct SharedMemory *)shmat(memoryID, (void *)0, 0);

	int newData;

	while (1) {
		newData = rand() % 10 + 1;

		while(sharedMem->count >= dataSize)
		{
			sleep(1);
		}

		sharedMem->string[sharedMem->count] = newData;
		(sharedMem->count) -= 1;

		printf("Produced: %d\n", newData);
		outputMemory(sharedMem);

		sleep(1);
	}

	shmdt(sharedMem);

	return 0;
}
