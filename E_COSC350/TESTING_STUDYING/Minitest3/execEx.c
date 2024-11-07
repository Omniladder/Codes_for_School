#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    pid_t child = fork();

    int childStatus;

    if(child != 0) //Parent
    {
        wait(&childStatus);
        for(int i = 50; i<=100; i++)
        {
            printf("%d ", i);
        }
    }
    else
    {
        execl("child", NULL);
    }

    return 0;

}