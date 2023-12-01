#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

struct SharedMemory {
	int string[5];
	int in;
	int out;
};

int main() {
	key_t key = ftok(".", -937700318);
	int memoryID = shmget(key, sizeof(struct SharedMemory), 0666);

	int dataSize = 5;
	struct SharedMemory *sharedMem = (struct SharedMemory *)shmat(memoryID, (void *)0, 0);


	while (1) {
		int newData = rand() % 10 + 1;

		while((sharedMem->in + 1) % dataSize == sharedMem->out)
		{
			printf("Full Buffer Waiting ...\n");
			sleep(1);
		}

		sharedMem->string[sharedMem->in] = newData;
		sharedMem->in = (sharedMem->in + 1) % dataSize;

		printf("Produced:\n");

		printf(" [");
		for (int i = 0; i < dataSize; ++i) {
			printf("%d", sharedMem->string[i]);
			if (i < dataSize - 1) {
				printf(", ");
			}
		}

		printf("]\n");

		sleep(1);
	}

	shmdt(sharedMem);

	return 0;
}
