#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t child = fork();
	if(child == 0)
	{
		printf("I AM THE CHILD");
		_exit(0);
	}
	else
	{
		while(1)
		{
			printf("I AM THE PARENT\n");
			sleep(1);
		}
	}
}
