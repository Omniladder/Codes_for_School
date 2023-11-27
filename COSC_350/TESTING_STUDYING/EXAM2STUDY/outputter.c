#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int main()
{
    char buff[80];
    while(read(0, buff, 80) > 0)
    {
        write(0, buff, 80);
    }
}