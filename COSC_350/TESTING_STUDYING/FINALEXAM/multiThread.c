#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void thread2(void*);
void thread3(void*);

void cancelation(void*);
void cancelation3(void*);

int main()
{
	pthread_t thr2, thr3;
	pthread_create(&thr3, NULL, thread3, (void*) pthread_self());
	pthread_create(&thr2, NULL, thread2, (void*) thr3);

	pthread_cleanup_push(cancelation, (void *)thr2);

	while(1)
	{
		pthread_testcancel();
		printf("IN THE ORIGINAL THREAD \n");
		sleep(1);
	}
	pthread_cleanup_pop(0);

	exit(0);
}


void thread3(void* hitList)
{
	pthread_cleanup_push(cancelation3, hitList);
	while(1)
	{
		pthread_testcancel();
		printf("IN THREAD 3\n");
		sleep(1);
	}
	pthread_cleanup_pop(0);
	exit(0);
}

void thread2(void* hitList)
{
	int count = 0;
	while(1)
	{
		if(count == 10)
		{pthread_cancel((pthread_t)hitList);}
		printf("IN THREAD 2\n");
		sleep(1);
		pthread_testcancel();
		count++;
	}
	exit(0);
}

void cancelation(void* hitList)
{
	printf("Orginal Thread is Killing Thread 3\n");
	pthread_cancel((pthread_t)hitList);
}

void cancelation3(void* hitList)
{
	printf("Thread 3 has killed Original Thread\n");
	pthread_cancel((pthread_t)hitList);
}
