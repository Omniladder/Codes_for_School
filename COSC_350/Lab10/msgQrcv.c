#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<errno.h>

int main()
{
    key_t key = ftok("./msgQsnd.c", 'A');

    int msgid, SHSIZE = 100;

    if ((msgid = msgget(key, 0644)) < 0)
    {
        perror("Queue Open Failed \n");
        exit (1);
    }

    while(msgrcv(msgid, ) != -1)
    {

    }
    
}