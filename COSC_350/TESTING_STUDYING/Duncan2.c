
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int numOfArgs, char* Inputs[])
{
	int inFile, outFile;
	int size = 0;
	if(numOfArgs != 3)
	{
	printf("INPUT PROPER NUMBER OF ARGUMENTS");
	return -1;
	}

	if( (inFile = open(Inputs[1], O_RDONLY)) < 0)
	{
	printf("YOUR INPUT OPEN DONE FUCKED UP");
	return -1;
	}
	
	if( (outFile = creat(Inputs[2], 0666)) < 0)
	{
	printf("YOUR OUTPUT CREATE DONE FUCKED UP");
	return -1;
	}

	char buff[1];

	while(read(inFile, buff, 1) > 0)
	{
		size++;
	}


	for(int i = 0; i < size; i++)
	{
	pread(inFile,buff,1, size - i - 1);
	if(buff[0] - '0' > 10 || buff[0] - '0' < 0)
		write(outFile, buff, 1);
	}

	return -1;

}
