//task5.c
//Date: 10/28/23
//Programmer: Jase Gambrill

#include <signal.h>
#include <stdio.h>

int main()
{
	sigset_t new;
	sigset_t old;
	
	sigemptyset(&new);
	sigaddset(&new, SIGINT);
	sigaddset(&new, SIGQUIT);
	
	sigprocmask(SIG_BLOCK, &new, &old);
	
	printf("Loop 1\n");
	
	sleep(2);
	
	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
	
	sigdelset(&new, SIGQUIT);
	sigprocmask(SIG_SETMASK, &new, NULL);
	
	printf("Loop 2\n");
	
	sleep(2);
	
	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
}
