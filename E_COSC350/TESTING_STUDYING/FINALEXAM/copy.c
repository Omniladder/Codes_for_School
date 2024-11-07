#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int numArguments, char** commandLine)
{
	umask(0);

	if( numArguments  != 3) //REMEMBER its always 1 greater than inputs since ./copy is one of the arguments
	{
		printf("PLEASE ENTER a File to copy from and the other file to copy too\n");
		exit(-1);
	}

	if(access(commandLine[1], F_OK) == -1)
	{
		printf("INPUT FILE DOESNT EXIST\n");
		exit(-1);
	}
	

	if(access(commandLine[1], R_OK) == -1)
	{
		printf("FILE 1 CAN'T READ FROM\n");
		exit(-1);
	}


	int outputFile = open(commandLine[2], O_CREAT | O_RDWR, 0666);
	int inputFile = open(commandLine[1], O_RDONLY, 0666);

	int oldCommandLineIn = dup(0);
	int oldCommandLineOut = dup(1);

	dup2(inputFile, 0);
	dup2(outputFile, 1);

	char buff[1];
	while(read(0, buff, 1) > 0)
	{write(1, buff, 1);}

	dup2(oldCommandLineIn, 0);
	dup2(oldCommandLineOut, 1);

	printf("FINISHED PROGRAM\n");

	close(inputFile);
	close(outputFile);	
}
