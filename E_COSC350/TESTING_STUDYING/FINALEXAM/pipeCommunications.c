#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void childDeath(int signal)
{
	printf("My Mother Has Murdered Me\n");
	exit(0);
}

void parentDeath(int signal)
{
	printf("Welp Toodle-oo \n");
	exit(0);
}


int main()
{
	int CtoPpipe[2];
	int PtoCpipe[2];

	if(pipe(CtoPpipe) == -1 || pipe(PtoCpipe) == -1)
	{
		printf("PIPE DIDNT WORK WAAAAAAAAHHHHHHHHH!!!!!\n");
		exit(-1);
	}

	pid_t child = fork();

	char buffer[20];

	if(child == 0) //THIS IS THE CHILD
	{
		signal(SIGTERM, childDeath);
		close(CtoPpipe[0]);
		close(PtoCpipe[1]);
		int i = 0;
		while(1)
		{
			printf("Hi Mom\n");
			write(CtoPpipe[1], "Hi Mom", 6); //USE PROPER SIZE
			read(PtoCpipe[0], buffer, 7); //USE PROPER SIZE
			printf("My Mommy Said %s\n", buffer);
			sleep(1);
		}
		close(CtoPpipe[1]);
		close(PtoCpipe[0]);
	}
	else //THIS IS THE PARENT
	{
		close(CtoPpipe[1]);
		close(PtoCpipe[0]);
		signal(SIGCHLD, parentDeath);
		
		int count = 0;
		while(1)
		{
			if(count == 5)
			{
				kill(child, SIGTERM);
			}
			
			read(CtoPpipe[0], buffer, 7);

			printf("My Son Said %s\n", buffer);
			printf("Shut Up\n");

			write(PtoCpipe[1], "Shut Up", 7);

			count++;
			sleep(1);
		}
		close(CtoPpipe[0]);
		close(PtoCpipe[1]);
	}
}
