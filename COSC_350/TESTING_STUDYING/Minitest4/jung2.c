#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

void thread1Kill(void* hitList)
{
	pthread_cancel((pthread_t)hitList);
	printf("THE FIRST THREAD JOB IS DONE\n");
}

void originalKill(void* hitList)
{
	printf("THE ORIGINAL THREAD JOB IS DONE\n");
}


void thread1(void* hitList)
{
	pthread_cleanup_push(thread1Kill, hitList);
	while(1)
	{
		pthread_testcancel();
		printf("THIS IS THE FIRST THREAD\n");
		sleep(1);
	}
	pthread_cleanup_pop(0);
	pthread_exit(0);
}

void thread2(void* hitList)
{
	for(int i = 0; i < 10; i++)
	{
		printf("THIS IS THE SECOND THREAD\n");
		sleep(1);
	}
	pthread_cancel((pthread_t) hitList);
	printf("Second Thread Job is Done\n");
	pthread_exit(0);
}

int main()
{
	pthread_t thr1, thr2;
	pthread_create(&thr1, NULL, thread1, (void *) pthread_self());
	pthread_create(&thr2, NULL, thread2, (void *) thr1);
	pthread_cleanup_push(originalKill, NULL);
	while(1)
	{
		pthread_testcancel();
		printf("THIS IS THE ORIGINAL THREAD\n");
		sleep(1);
	}
	pthread_cleanup_pop(0);
	pthread_exit(0);
}
