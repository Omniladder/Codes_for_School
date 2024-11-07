#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/msg.h>


struct message
{
    char msgArray[256];
    long msgId;
};

int main()
{
    key_t key = ftok("msgQsnd.c", 'A');

    int msgid;

    if ((msgid = msgget(key, 0644)) < 0)
    {
        perror("Queue Open Failed \n");
        exit (1);
    }

struct message msg;

int num1, num2;
msg.msgId = 1;


    while(msgrcv(msgid, (struct message *) &msg, sizeof(msg), 0, 0) != -1)
    {
	if(sscanf(msg.msgArray, "%d %d", &num1, &num2) == 2)
	{
		printf("The Sum is : %d \n", num1 + num2);
	}
	else
	{
		printf("INVALID RESPONSE\n");
	}
    }
}
