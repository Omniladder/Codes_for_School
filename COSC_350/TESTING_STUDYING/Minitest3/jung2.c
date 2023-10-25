#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t child, grandchild;
	int childStatus;
	child = fork();

	if(child == 0)
	{
		grandchild = fork();
	}

	if(child != 0) //this is grandparent
	{
		while(!WIFEXITED(childStatus))
		{
			sleep(1);
			printf("I AM YOUR PARENT\n");	
			waitpid(child, &childStatus, WNOHANG);
		}
		printf("I FINISHED MY JOB\n");
		exit(0);
	}
	else
	{

	if(grandchild != 0) //CHILD
	{
		for(int i = 0; i < 3; i++)
		{
			sleep(1);
			printf("I am your child\n");
		}
		exit(0);
	}
	else //GRANDCHILD
	{
		grandchild = getppid();
		while(1)
		{
			if(getppid() == grandchild)
			{
			sleep(1);
			printf("I am your grandchild\n");
			}
			else
			break;
		}
		exit(0);
	}


	}

	return 0;

}
