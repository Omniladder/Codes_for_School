#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{

	int pipeFd[2];

	if(pipe(pipeFd) == -1)
	{
		printf("FAILED TO MAKE PIPE\n");
		exit(-1);
	}

	int num1, num2;
	
	pid_t child = fork(); //REMEMBER TO FORK THE CHILD

	if(child == 0) //Child
	{
		close(pipeFd[1]); //remember to close
		char string[20];
		snprintf(string, sizeof(string), "%d", pipeFd[0]);
		execl("./adderChild", "./adderChild", string, (char *)NULL); //REMEMBER NULL AT THE ENDN
	}
	else
	{
		char buff[256];
		int intArray[2];
		close(pipeFd[0]); //Remember to close
		while(read(0, buff, 256) > 0)
		{
			if(sscanf(buff, "%d %d", &intArray[0], &intArray[1]))
				write(pipeFd[1], intArray, sizeof(int) * 2);
			else
				printf("INVALID INPUT\n");
		}
		close(pipeFd[1]);
	}
	exit(0);
}
