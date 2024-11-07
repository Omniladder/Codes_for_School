#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void DING(int sig)
{
	printf("DING!!!\n");
	exit(0);
}

int main()
{
	signal(SIGALRM, DING);

	alarm(5);

	while(1)
	{
		sleep(1);
		printf("One Second Has Passed ...\n");
	}
	
}
