#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>



struct SharedMemory 
{
	int string[5];
};

int main() {

	key_t key = ftok(".", -937700319);
	int memoryID = shmget(key, sizeof(struct SharedMemory), 0666);

	int dataSize = 5;
	

	struct SharedMemory *memory = (struct SharedMemory *)shmat(memoryID, (void *)0, 0);


	int consumedData;

	while (1) {
		while(memory->in == memory->out) {
			printf("Buffer is empty. Consumer waits.\n");
			sleep(1);
		}

		consumedData = memory->string[memory->out];
		memory->string[memory->out] = 0;
		memory->out = (memory->out + 1) % dataSize;

		printf("Consumed: %d\n", consumedData);
		printf("Shared Memory Contents: [");
		for (int i = 0; i < dataSize; ++i) {
			printf("%d", memory->string[i]);
			if (i < dataSize - 1) {
				printf(", ");
			}
		}
		printf("]\n");

		sleep(1);
	}

	shmdt(memory);

	return 0;
}
