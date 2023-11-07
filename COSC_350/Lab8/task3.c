#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void bye1 (void*);
void bye (void *);

void thread1(void*);
void thread2(void*);


int main()
{
    pthread_t thread1, thread2;
    pthread_create();
}


void thread1(void* hitList)
{

}

void thread2(void* hitList)
{

}


void bye(void* input)
{
    printf("Bye\n");
    exit;
}
void bye1(void* input)
{
    printf("END OF THE PROGRAM\n");
    exit;
}