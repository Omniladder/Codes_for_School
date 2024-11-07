#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();

    if(child > 0)
    {
        sleep(500);
    }
    else
    {
        exit(0);
    }

    exit(0);


}