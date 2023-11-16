#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void bye1 (void*);
void bye (void *);

void thread1(void*);
void thread2(void*);


int main()
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, (void *)thread1, (void *) pthread_self());
    pthread_create(&thread_2, NULL, (void *)thread2, (void *) thread_1);

    pthread_cleanup_push(bye1, NULL);
    while(1)
    {
        printf("IN THE ORIGINAL THREAD\n");
        sleep(1);
	pthread_testcancel();
    }
    pthread_cleanup_pop(0);
    pthread_exit(0);
}


void thread1(void* hitList)
{
    pthread_cleanup_push(bye, hitList);
    while(1)
    {
        printf("IN THE FIRST THREAD \n");
        sleep(1);
	pthread_testcancel();
    }
    pthread_cleanup_pop(0);
    pthread_exit(0);
}

void thread2(void* hitList)
{
    int count = 0;
    while(1)
    {
        count++;
	printf("IN THE SECOND THREAD \n");
	sleep(1);
        if(count >= 10)
        {
		pthread_cancel((pthread_t) hitList);
		break;
        }
    }
    pthread_exit(0);

}


void bye(void* hitList)
{
    printf("Bye\n");
    pthread_cancel((pthread_t) hitList);
}
void bye1(void* input)
{
    printf("END OF THE PROGRAM\n");
}
