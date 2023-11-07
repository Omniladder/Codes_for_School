#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>


void thread1(void* hitList)
{
	while(1)
	{
	
		pthread_testcancel();
		printf("THIS IS THE FIRST THREAD\n");
		sleep(1);
	}
}

void thread2(void* hitList)
{
	for(int i = 0; i < 10; i++)
	{
	printf("THIS IS THE SECOND THREAD\n");
	}
	pthread_cancel((pthread_t) hitList);
	printf("Second Thread Job is Done\n");
	return;
}

int main()
{

}
