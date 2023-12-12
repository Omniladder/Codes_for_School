#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/msg.h>

struct message
{
    int msgArray[2];
    long msgId;
};

int main()
{
	struct message msg;

	key_t msgKey;
	int msgId;

	if((msgKey = ftok(".", 'Q')) == -1)
	{
		perror("Failed to Create Message Queue Key");
		exit(-1);
	}

	if((msgId = msgget(msgKey, 0)) == -1)
	{
		perror("Failed to Grab Message Queue");
		exit(-1);
	}

	pid_t child;

	if((child = fork()) == -1)
	{
		perror("Fork Failed");
		exit(-1);
	}


	if(child == 0) //Child
	{
		while(msgrcv(msgId, &msg, sizeof(struct message), 0, 0) != -1)
		{
			printf("Sum is %d\n", msg.msgArray[0] + msg.msgArray[1]);
		}

	}
	else//Parent
	{
		char buff[256];
		int num1, num2;
		while(fgets(buff, sizeof(buff), stdin) > 0)
		{
			if(sscanf(buff, "%d %d", &(msg.msgArray[0]), &(msg.msgArray[1])) == 2)
			{
				msgsnd(msgId, &msg, sizeof(msg), 0);
			}
			else
			{
				printf("INVALID INPUT\n");
			}
		}
			kill(child, SIGTERM);
	}
	exit(0);
}
