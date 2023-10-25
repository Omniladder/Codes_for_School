#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int numInputs, char* commandLine[])
{
    char buff[1];
    int file = open(commandLine[1], O_RDONLY);
    pid_t child = fork();
    int loc = 0;

    if(child == 0) //PARENT
    {
        int out = creat("parent.txt", 0666);
        while(1)
        { 
            lseek(file, loc, SEEK_SET);
            if(read(file, buff, 1) <= 0)
            {break;}
            write(out, buff, 1);
            loc++;
        }

    }
    else
    {
        int out = creat("child.txt", 0666);
        while(1)
        {
            lseek(file,loc, SEEK_SET);
            if(read(file, buff, 1) <= 0)
            {break;}
            write(out, buff, 1);
            loc++;
        }

    }


}