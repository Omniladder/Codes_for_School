#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>



struct SharedMemory {
	int string[5];
	int in;
	int out;
};

int main() {

	key_t key = ftok("aB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpC", -937700319);
	int memoryID = shmget(key, sizeof(struct SharedMemory), 0666);

	int dataSize = 5;
	
	if (memoryID == -1) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	struct SharedMemory *memory = (struct SharedMemory *)shmat(memoryID, (void *)0, 0);

	if (memory == (struct SharedMemory *)(-1)) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	while (1) {
		while(memory->in == memory->out) {
			printf("Buffer is empty. Consumer waits.\n");
			sleep(1);
		}

		int consumedData = memory->string[memory->out];
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
