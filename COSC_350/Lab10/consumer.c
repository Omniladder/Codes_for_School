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
	int shmid = shmget(key, sizeof(struct SharedMemory), 0666);

	int dataSize = 5;
	
	if (shmid == -1) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	struct SharedMemory *shrMem = (struct SharedMemory *)shmat(shmid, (void *)0, 0);

	if (shrMem == (struct SharedMemory *)(-1)) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	while (1) {
		while(shrMem->in == shrMem->out) {
			printf("Buffer is empty. Consumer waits.\n");
			sleep(1);
		}

		int consumedData = shrMem->string[shrMem->out];
		shrMem->string[shrMem->out] = 0;
		shrMem->out = (shrMem->out + 1) % dataSize;

		printf("Consumed: %d\n", consumedData);
		printf("Shared Memory Contents: [");
		for (int i = 0; i < dataSize; ++i) {
			printf("%d", shrMem->string[i]);
			if (i < dataSize - 1) {
				printf(", ");
			}
		}
		printf("]\n");

		sleep(1);
	}

	shmdt(shrMem);

	return 0;
}
