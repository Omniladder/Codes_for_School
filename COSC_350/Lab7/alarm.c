
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig) {
alarm_fired = 1;
}

int main()
{
	pid_t pid;


	printf("alarm application starting\n");

	struct sigaction sig;
	sig.sa_handler = ding;
	sigemptyset(&sig.sa_mask);

	if (sigaction(SIGINT, &sig, 0)) {
	perror ("sigaction");
	return 1;
	}


	pid = fork();
	switch(pid)
	{
	case -1:
		perror("fork failed");
		exit(1);
	
	case 0:
		sleep(5);
		kill(getppid(), SIGINT);
		_exit(0);
	}

	printf("waiting for alarm to go off\n");

	signal(SIGINT, ding);
	pause();

	if(alarm_fired)
		printf("DING!\n");

	printf("done\n");
	exit(0);
}
