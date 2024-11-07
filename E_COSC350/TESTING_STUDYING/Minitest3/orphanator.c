#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t future_Orphan = fork();

    if(future_Orphan != 0)
    {
        _exit(0);
    }
    else
    {
        sleep(10);
    }

    return 0;
}