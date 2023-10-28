#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

    pid_t childID = fork();

    char* childOutput = "Hi, Mom\n";
    int childStatus;
    char parentInput[sizeof(childOutput) / sizeof(char)];

    if(childID == 0)
        {
        int out = creat("foo.txt", 0666);
        write(out, childOutput, sizeof(childOutput) / sizeof(char));
        }
        else
        {
        wait(&childStatus);
        int in = open("foo.txt", O_RDONLY);
        read(in, parentInput, sizeof(childOutput) /  sizeof(char));
        printf("My son said %s", parentInput);
        }
    return 0;
}