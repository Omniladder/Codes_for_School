#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void KillChild(int);
void KYS(int);

int main()
{
	pid_t child, grandchild;
	child = fork();

	if(child != 0) //Grandparent
	{
		signal(SIGUSR2, KYS);
		while(1)
		{
			printf("grandparent process\n");
		}

	}
	else if(child != 0) //child
	{
		signal(SIGUSR1, KillChild);

		while(1)
		{
			printf("child process\n");
		}
	}
	else //grandchild
	{

		for(int i = 0; i < 10; i++)
		{
			printf("grandchild process\n");
		}
		pthread_t biologicalParent = getppid();
		kill(getppid(), SIGUSR1);
		while(getppid() != biologicalParent)
		{;}
		exit(0);


	}
}

void KillChild(int signal)
{
	kill(getppid(), SIGUSR2);
	exit(0);
}

void KYS(int signal)
{
	exit(0);
}
