
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int numofArgs, char* Inputs[])
{
umask(0);

int inFile, outFile;

if(numofArgs < 3)
{
	printf("PLEASE ENTER IN TWO FILENAMES FIRTS IS FOR INPUT SECOND IS FOR OUTPUT");
	return -1;
}

if((inFile = open(Inputs[1], O_RDONLY)) < 0)
{
	printf("INPUT FILE FAILED TO OPEN");
	return -1;
}

if((outFile = creat(Inputs[2], 0666)) < 0)
{
	printf("OUTPUT FILE FAILED TO OPEN");	
	return -1;
}

int size  = 0;
char buff[1];

while(read(inFile, buff, 1) > 0)
{
size++;
}

for(int i = 0; i < size; i++)
{
	pread(inFile, buff, 1, size - i - 1);
	if( buff[0] - '0' < 0 || buff[0] - '0' > 10)
	write(outFile, buff, 1);
}

return 0;
}
