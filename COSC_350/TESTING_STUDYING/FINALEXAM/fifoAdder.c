#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	pid_t child;

	int numBuff[2];
	
	child = fork();

	if(child == 0)// THIS IS THE CHILD
	{
		char buff[256];
		int fifo = open("/tmp/fifo", O_RDWR);
		while(fgets(buff, 256, stdin) != NULL)
		{
			if(sscanf(buff, "%d %d", &numBuff[0], &numBuff[1]) == 2)
				write(fifo, numBuff, sizeof(int) * 2);
			else
				printf("INVALID INPUT\n");
		}
		close(fifo);
	}
	else
	{
		int fifo = open("/tmp/fifo", O_RDONLY);
		while(read(fifo, numBuff, sizeof(int) * 2) > 0)
		{
			printf("Sum is %d\n", numBuff[0] + numBuff[1]);//REMEMBER \n
		}
		close(fifo);
	}
	exit(0);

}
