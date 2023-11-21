#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* fun1 (void*); void* fun2(void*); void* fun3(void*);

void main(int numArgs, char* commandLine[])
{
	pthread_t thread1, thread2, thread3;
	void* buff;
	pthread_create(&thread1, NULL, fun1, (void*) commandLine[1]);
	pthread_join(thread1, &buff);
	pthread_create(&thread2, NULL, fun2, buff);
	pthread_join(thread2, &buff);
	pthread_create(&thread3, NULL, fun3, buff);
	pthread_join(thread3, &buff);

	printf("the three threads calculation is %d\n", ((int) buff));
	exit(0);
}

void* fun2(void* input)
{
	return (void *)(((int)input) + 20);
}

void* fun3(void* input)
{
	return (void *)(((int) input) + 30);
}

void* fun1(void* input)
{
	int num = atoi((char*) input);
	return (void*) num + 10;
}
