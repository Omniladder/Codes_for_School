#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct SharedMemory
{
	int data[5];
	int in;
	int out;
};

int main()
{
	key_t key = ftok("aB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpCaB3#kL7*qp2!zR9xY5cV1&fG8hJ6uQ0iX4sN!tZmWpC", -937700319);
	int shmid = shmget(key, sizeof(struct SharedMemory), 0666 | IPC_CREAT);

	if(shmid == 1)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	struct SharedMemory *shm = (struct SharedMemory *)shmat(shmid, (void *)0, 0);

	if (shm == (struct SharedMemory *)(-1))
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	shm->in = 0;
	shm->out = 0;

	printf("Shared Memory created successfully\n");

	shmdt(shm);

	return 0;
}
