
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char* convIntToStr(int, char*);

int main(int numOfArgs, char* Inputs[])
{
	int inFile;
	int num = 0;

	if(numOfArgs != 2)
	{
	printf("IMPROPER NUMBER OF ARGUMENTS");
	return -1;
	}

	if((inFile = open(Inputs[1], O_RDONLY)) < 0)
	{
	printf("YOUR FILE DING DONILY FAILED BITCH");
	return -1;
	}

	char buff[80];

	while(read(inFile, buff, 1) > 0)
	{
	if(buff[0] - '0' < 10 && buff[0] - '0' > 0)
	num = num * 10 + buff[0] - '0'; 
	
	}

	num+=10;

	printf("%s", convIntToStr(num, buff));

	return -1;
}

char* convIntToStr(int x, char* string)
{
	sprintf(string, "%d", x);
	return string;
}
