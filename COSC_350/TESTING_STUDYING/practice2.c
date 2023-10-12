
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int numOfInputs, char* Inputs[])
{
	if(numOfInputs != 5)
	{
	printf("MUST ENTER 3 INPUTS");
	return -1;
	}

	int inFile1, outFile1, outFile2, outFile3;

	if(inFile1 = open(Inputs[1], O_RDONLY) < 0)
	{
	printf("FAILED TO OPEN FILE");
	return -1;
	}

	if(outFile1 = creat(Inputs[2] , 0666) < 0)
	{
	printf("FAILED TO CREATE FILE");
	return -1;
	}

	if(outFile2 = creat(Inputs[3] , 0666) < 0)
	{
	printf("FAILED TO CREATE FILE");
	return -1;
	}
	
	if(outFile3 = creat(Inputs[4], 0666) < 0)
	{
	printf("FAILED TO CREATE ");
	return -1;
	}

	int size = 0;
	int isPalin = 1;
	char buff[1];
	char buff2[1];
	char space[1];

	space[0] = ' ';

	while(read(inFile1, &buff, 1) > 0)
	{
	if(buff[0] - '0' >= 0 && buff[0] - '0' < 10)
	{
	write(outFile1, space, 1);
	write(outFile2, buff, 1);
	}
	else
	{
	write(outFile1, buff, 1);
	write(outFile2, space,1);
	write(outFile3, buff, 1);
	}
	size++;
	printf("TEST\n");
	}

	for(int i = 0; i < size; i++)
	{
	pread(outFile1, buff, 1, i );
	pread(outFile1, buff2, 1, size -i - 1);
	if(buff[0] != buff2[0])
	{
		isPalin = 0;
		break;
	}
	}

	if(isPalin)
	{
	printf("FILE IS A PALINDROME");
	}
	else
	{
	printf("FILE ISN'T A PALINDROME");
	}

	return 0;
}
