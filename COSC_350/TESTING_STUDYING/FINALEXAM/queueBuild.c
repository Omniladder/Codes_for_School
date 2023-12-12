#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/msg.h>

int main()
{
	key_t queueKey;
	int queueId;

	if((queueKey = ftok(".", 'Q')) == -1)
	{
		perror("Queue Key Failed to Build");
		exit(-1);
	}

	if((queueId = msgget(queueKey, 0666 | IPC_CREAT)) == -1)
	{
		perror("Queue Failed to Build");
		exit(-1);
	}
}
