#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

volatile int niceResponseTriggered = 0;
volatile int meanResponseTriggered = 0;

void  niceGuyResponse(int Sang_Eon_Park)
{
    printf("Hi Honey! Anything Wrong\n");
    niceResponseTriggered = 1;
}

void  meanGuyResponse(int Sang_Eon_Park)
{
    printf("Do you make trouble again\n");
    meanResponseTriggered = 1;
}

int main()
{
    pid_t favoriteChild, actuallySatan;



    signal(SIGUSR1, &niceGuyResponse);
    signal(SIGUSR2, &meanGuyResponse);

    favoriteChild = fork();
    
    if(favoriteChild != 0)
    {
        waitpid(favoriteChild, 0, 0);
        actuallySatan = fork();
    }

    if(favoriteChild == 0)
    {
        kill(getppid(), SIGUSR1); //WHY IN GODS GREEN EARTH IS THE SEND SIGNAL COMMAND CALLED KILL
    	exit(0);
    }
    else if(actuallySatan == 0)
    {
        kill(getppid(), SIGUSR2);
    	exit(0);
    }
    else
    {
        waitpid(actuallySatan, 0, 0);
    }

    return 0;
}
