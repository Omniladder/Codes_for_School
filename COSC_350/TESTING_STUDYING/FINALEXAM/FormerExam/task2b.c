#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

struct message{
	char nums[256];
	int running;
}

struct sharedMemory{
	int nums[2];
	int running;
}

int main()
{
	key_t key = ftok(".", 'B');

	int msgId = msgget(key, 0666);

	int shmId = shmget(key, sizeof(sharedMemory), 0666 | IPC_CREAT);


	struct message msg;

	msg = (struct sharedMemory)shmat(shmId, sizeof(struct message), 0);

	memory.running = 1;

	msg.running = 1;
	int num1, num2;

	while(msgrcv(msgId, &msg, sizeof(struct message, 0, 0)) != -1 || msg.running != -1)
	{
		if(sscanf(msg.nums, "%d %d", &num1, &num2) == 2)
		{
			memory.nums[0] = num1;
			memory.nums[1] = num2;
		}
		else
		{
			printf("INVALID INPUT\n");;
		}
	}

	memory.running = -1;

}
