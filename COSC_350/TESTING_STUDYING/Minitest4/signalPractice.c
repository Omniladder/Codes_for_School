#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void terminate(int sig)
{
	if(sig == SIGUSR1)
	{
		printf("Mom says I need to Study\n");
		abort();
	}
	else if(sig == SIGCHLD)
	{
		printf("Please Don't Interrupt my Son he is studying\n");
		abort();
	}
}

int main()
{
	pid_t child;
	child = fork();

	if(child == 0)
	{
		signal(SIGUSR1, terminate);
		while(1)
		{
			printf("MOM I WANT TO PLAY FOREVER\n");
			sleep(1);
		}
	}
	else
	{
		int count = 0;
		signal(SIGCHLD, terminate);
		while(1)
		{
			if(count == 10)
			{kill(child, SIGUSR1);}
			
			printf("It's Time to Study\n");
			sleep(1);
			count++;
		}
	}
	return 0;
}
