#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void doesNothing()
{;}

int main()
{
	sigset_t mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);

	sigprocmask(SIG_BLOCK, &mask, NULL);

		for(int i = 1; i <= 5; i++ )
		{
			printf("%d\n", i);
			sleep(1);
		}
	
		sigdelset(&mask, SIGQUIT);
		signal(SIGINT, &doesNothing);//SETS SIGNAL TO DO NOTHING SO THAT THE POTENTIALLY QUEUED UP CODE DOESNT END THE PROGRAM
		sigprocmask(SIG_UNBLOCK, &mask, NULL);
		signal(SIGINT, SIG_DFL); //SETS SIGNAL BACK TO DEFAULT
		

		for(int i = 6; i <= 10; i++ )
		{
			printf("%d\n", i);
			sleep(1);
		}

		exit(0);
}
