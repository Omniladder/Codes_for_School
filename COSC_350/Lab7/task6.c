
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

void parentKill(int pKill)
{
	exit(0);
}

void childKill(int cKill)
{
	kill(getppid(), SIGUSR2);
	exit(0);
}


int main()
{
	signal(SIGUSR2, parentKill);
	signal(SIGUSR1, childKill);
	
	
	pid_t child = fork(), grandChild;
	
	if(child == 0)
	{
		grandChild = fork();
	}

	if(child != 0)
	{
		while(1)
		{
		printf("parent process\n");
		}	
	}
	else if(grandChild != 0)
	{
		while(1)
		{
		printf("Child Process\n");
		}
	}
	else
	{
		for(int i = 0; i < 10; i++)
		{
		printf("Grandchild Process\n");
		}
		kill(getppid(), SIGUSR1);
	}
	exit(0);
}
