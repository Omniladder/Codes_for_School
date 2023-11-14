#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int fileDescriptor1[2];
	int fileDescriptor2[2];
	
	pipe(fileDescriptor1);
	pipe(fileDescriptor2);
	
	char buff[256];
	
	pid_t child = fork();

	if(child != 0)
	{
		write(fileDescriptor1[1], "I LOVE YOU", 256);

		while(read(fileDescriptor2[0], buff, 256) == 0)
		{}

		printf("My Son Said %s\n", buff);
	}
	else
	{
		while(read(fileDescriptor1[0], buff, 256) == 0)
		{}

		printf("My mom said %s\n", buff);

		write(fileDescriptor2[1], "I LOVE YOU TOO", 256);
	}
}
