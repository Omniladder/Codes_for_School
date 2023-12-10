#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int numCommands, char** commandLine)
{
	if(numCommands != 2)
	{
		printf("IMPROPER NUMBER OF COMMANDS INPUTTED\n");
		exit(-1);
	}

	int inputPipe = atoi(commandLine[1]);
	int buff[2];

	int sum = 0;
	while(read(inputPipe, buff, 256) > 0)
	{
		sum = buff[0] + buff[1];
		printf("SUM IS %d\n", sum);
	}
	close(inputPipe);
	exit(-1);
}
