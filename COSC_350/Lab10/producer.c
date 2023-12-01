#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

struct SharedMemory {
	int data[5];
	int in;
	int out;
};

int main() {
	key_t key = ftok("aB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpC", -937700319);
	int shmid = shmget(key, sizeof(struct SharedMemory), 0666);

	if(shmid == -1) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	struct SharedMemory *shm = (struct SharedMemory *)shmat(shmid, (void *)0, 0);

	if(shm == (struct SharedMemory *)(-1)) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	while (1) {
		int newData = rand() % 10 + 1;

		while((shm->in + 1) % SHM_SIZE == shm->out)
		{
			printf("Buffer is full. Producer waits.\n");
			sleep(1);
		}

		shm->data[shm->in] = newData;
		shm->in = (shm->in + 1) % SHM_SIZE;

		printf("Produced: %d\n", newData);

		printf("Shared Memory Contents: [");
		for (int i = 0; i < SHM_SIZE; ++i) {
			printf("%d", shm->data[i]);
			if (i < SHM_SIZE - 1) {
				printf(", ");
			}
		}

		printf("]\n");

		sleep(1);
	}

	shmdt(shm);

	return 0;
}
