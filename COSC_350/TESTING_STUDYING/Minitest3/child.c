#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    for(int i = 0; i< 50; i++)
    {
        printf("%d ", i);
    }
}