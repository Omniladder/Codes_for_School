#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();

    if(child == 0)
    {
        while(1)
        ;
    }
    else
    {
        _exit(0);
    }
}