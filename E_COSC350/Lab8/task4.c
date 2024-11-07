#include <signal.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



int main()
{
	int fileDescriptor[2];

	pid_t child;
	pipe(fileDescriptor);
	
	child = fork();


	if(child == 0)
	{
		close(fileDescriptor[1]);
		char buff[256];
		int sum = 0;
		int numberInputs1;
		int numberInputs2;

		while(1)
		{

			if (read(fileDescriptor[0], buff, 256) > 0)
			{
			if(sscanf(buff, "%d%d", &numberInputs1, &numberInputs2) == 2)
			{
				printf("SUM IS %d\n", numberInputs1 + numberInputs2);
			}
			else if(strcmp(buff,"EOF") == 0)
			{
				break;
			}
			else
			{
				printf("INVALID INPUT\n");
			}
			}
		}
	
		kill(getppid(), SIGTERM);
		close(fileDescriptor[0]);
	}
	else
	{
		close(fileDescriptor[0]);
		char num1[256]; 
		char num2[256];
		char buff[256];
		while(1)
		{

			scanf("%s", num1);
			if(strcmp(num1, "EOF") == 0)
			{
				write(fileDescriptor[1], "EOF", 256);
			}
			scanf("%s", num2);

			if(strcmp(num2, "EOF") == 0)
			{
				write(fileDescriptor[1], "EOF", 256);
			}
			
			concatenate(num1, num2, buff);

			
			write(fileDescriptor[1], buff, 256);
		}
		close(fileDescriptor[1]);
	}
	int status;

	waitpid(child, &status, 0);
	return 0;
}
