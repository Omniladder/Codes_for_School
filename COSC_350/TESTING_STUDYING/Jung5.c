#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int numArgs, char* Inputs[])
{

	if(numArgs < 3)
	{
	printf("ENTER IN 2 FILES FIRST IS INPUT SECOND IS OUTPUT");
	return -1;
	}

	umask(0);

	int inFile, outFile;
	char buff[1];

	if ((inFile = open(Inputs[1], O_RDONLY)) < 0)
	{
	printf("INPUT FILE FAILED TO OPEN");
	return -1;
	}
	if ((outFile = creat(Inputs[2], 0666)) < 0)
	{
	printf("OUTPUT FILE FAILED TO OPEN");
	return -1;
	}

	dup2(outFile, 1);
	while(read(inFile, buff, 1) && (int) buff[0] != 10 )
	{
	printf("%d ",(int) buff[0]);
	}
}
