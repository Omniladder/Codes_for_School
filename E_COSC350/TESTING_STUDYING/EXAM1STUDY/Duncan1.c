
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int numofArgs, char* Inputs[])
{
	umask(0);
	if(numofArgs < 3)
	{
	printf("ENTER PROPER NUMBER OF FILES \n");
	return -1;
	}

	int inFile, outFile;
	if((inFile = open(Inputs[1], O_RDONLY)) < 0)
	{
	printf("IN FILE FAILED TO OPEN \n");
	return -1;
	}

	if((outFile = creat(Inputs[2], 0666)) < 0)
	{
	printf("OUT FILE FAILED TO OPEN \n");
	return -1;
	}

	dup2(outFile, 1);
	char buff[1];
	int size = 0;

	while(read(inFile, buff, 1) > 0)
	{
	size++;
	}

	for(int i = 0; i < size; i ++)
	{
	pread(inFile, buff, 1, i);
	printf("%d ", buff[0]);
	}


}
