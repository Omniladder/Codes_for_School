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
        return 0;
    }
    else
    {
       while(1)
       {} 
    }
    return 0;
}