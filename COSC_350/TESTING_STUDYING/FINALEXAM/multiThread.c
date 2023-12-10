#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void thread2(void*);
void thread3(void*);

void cancelation1(void*);
void cancelation2(void*);

int main()
{
	pthread_t thr2, thr3;
	pthread_create(&thr3, NULL, thread3, (void*) pthread_self());
	pthread_create(&thr2, NULL, thread2, (void*) thr3);

	while(1)
	{
		printf("IN THE ORIGINAL THREAD \n");
		sleep(1);
		pthread_testcancel();
	}

}
