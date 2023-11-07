#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void killChild(int signal)
{
	printf("my said \" GO AWAY\"\n");
	abort();
}

void KYS(int signal)
{

	for(int i = 0; i < 3; i++)
	{
	sleep(1);
	printf("I AM SORRY MY SON\n");
	}
	abort();
}

int main()
{
	pid_t child;
	signal(SIGUSR1, &killChild);
	signal(SIGCHLD,&KYS);
	child = fork();
	if(child == 0)
	{
	while(1)
	{
		printf("I AM IMMORTAL\n");
		sleep(1);
	}
	}
	else
	{
	for(int i = 0; i < 10; i++)
	{
		printf("THIS IS YOUR MOM\n");
		sleep(1);
	}
	kill(child, SIGUSR1);
	while(1){;} //WAITS FOR SON TO DIE
	}
}
