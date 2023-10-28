#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

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



    struct sigaction niceResponse;
    struct sigaction meanResponse;
        
    niceResponse.sa_handler = niceGuyResponse;
    meanResponse.sa_handler = meanGuyResponse;

    sigaction(SIGUSR1, &niceResponse, NULL);
    sigaction(SIGUSR2, &meanResponse, NULL);

    favoriteChild = fork();
    
    if(favoriteChild != 0)
    {
        actuallySatan = fork();
    }

    if(favoriteChild == 0)
    {
        kill(getppid(), SIGUSR1); //WHY IN GODS GREEN EARTH IS THE SEND SIGNAL COMMAND CALLED KILL
    }
    else if(actuallySatan == 0)
    {
        kill(getppid(), SIGUSR2);
    }
    else
    {
        while(!(meanResponseTriggered && niceResponseTriggered))
        {
        }
    }
    return 0;
}