#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void emptySignal(int sig)
{;}
int main()
{
	sigset_t termsToChange;
	sigset_t storedTerms;
	
	sigaddset(&termsToChange, SIGINT);
	sigaddset(&termsToChange, SIGQUIT);
	
	sigprocmask(SIG_BLOCK, &termsToChange, &storedTerms);
	
	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	signal(SIGQUIT, &emptySignal);

	sigdelset(&termsToChange, SIGINT);
	sigprocmask(SIG_UNBLOCK, &termsToChange, &storedTerms);
	
	signal(SIGQUIT, SIG_DFL);

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
	return 0;
}
