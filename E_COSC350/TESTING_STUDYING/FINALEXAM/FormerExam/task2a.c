#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>


struct message
{
	char nums[256];
	int running;
}

int main()
{
	key_t key = ftok(".", 'B');

	int msgId = msgget(key, 0666 | IPC_CREAT);


	struct message msg;

	char buff[256];


		while(fgets(buff, sizeof(buff), stdin) > 0)
		{
			msgsnd(msgId, &msg, sizeof(msg), 0);
		}
	msg.running = -1;
	msgsnd(msgId, &msg, sizeof(msg), 0);
}
