#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<errno.h>
#include <sys/msg.h>

struct message
{
    char msgArray[256];
    int msgId;
};

int main()
{
    key_t key = ftok("msgQsnd.c", 'A');

    if(key < 0)
    {

        perror("Key Making Failed \n");
        exit (1);
    }

    int msgid, SHSIZE = 100;

    if ((msgid = msgget(key, 0644 | IPC_CREAT)) < 0)
    {
        perror("Queue Open Failed \n");
        exit (1);
    }

   struct message msg;

    msg.msgId = 1;
    int error;

    do
    {
        printf("Input Two Integer Values\n");
        error = scanf("%s", msg.msgArray);
        msgsnd(msgid, &msg, sizeof(msg), 0);
    } while (error != -1);


    msgctl(msgid, IPC_RMID, NULL);
    exit(0);
} 