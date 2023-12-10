#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t child;

	child = fork();
	if(child == 0)
	{
		for(int i = 1; i <= 5; i++)
		{
			printf("%d \n", i);
			sleep(1);
		}
	}
	else
	{
		int status;
		wait(&status); //MAKE THIS A POINTER

		for(int i = 6; i <= 10; i ++)
		{
			printf("%d\n", i);
			sleep(1);
		}
	}
	exit(0);
}

