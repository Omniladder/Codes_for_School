#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void thread1(void*);
void thread2(void*);
void Bye1(void*);
void Bye(void*);

int main()
{
	pthread_t thread_1, thread_2;
	
	pthread_create(&thread_1, NULL, thread1, pthread_self());
	pthread_create(&thread_2, NULL, thread2, thread_1);
	
	pthread_cleanup_push(Bye1, NULL);
	while(1)
	{
		printf("IN SIDE OF ORIGINAL THREAD\n");
		pthread_testcancel();
		sleep(1);
	}
	pthread_cleanup_pop(0);
}




void Bye1(void* input)
{
	printf("END OF PROGRAM\n");
	exit(0);
}

void Bye(void* Hit)
{
	printf("BYE!\n");
	kill(SIGTERM, (pthread_t) Hit);
	exit(0);
}

void thread1(void* Hit)
{
	pthread_cleanup_push(Bye, Hit);
	while(1)
	{
		printf("in First Thread\n");
		pthread_testcancel();
		sleep(1);
	}
	pthread_cleanup_pop(0);
}

void thread2(void* Hit)
{
	int i = 0;
	while(1)
	{
		printf("In the second Thread\n");
		if(i > 10)
		{pthread_cancel((pthread_t)Hit);}
		i++;
		sleep(1);
	}//I THINK THIS CREATES AN INFINITE LOOP NEVER BROKEN OUT OF IDK IT NEVER SAYS TO TERMINATE
}
