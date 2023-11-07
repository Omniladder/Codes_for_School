#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int gvalue = 10;

void main()
{
	char* sID;
	int iStack = 20;

	pid_t pID = fork();

	if(pID == 0)
	{
		sID = "Child Process: ";
		gvalue++;
		iStack++;
	}
	else if (pID < 0)
	{
		printf("Failed to fork\n");
		exit (1);
	}
	else
	{
		wait(NULL);
		sID = "Parent Process: ";
		gvalue=gvalue+5;
		iStack= iStack + 5;
	}
	printf("%s\n", sID);
	printf(" Global variable: %d\n", gvalue);
	printf(" stack variable: %d\n", iStack);
}

