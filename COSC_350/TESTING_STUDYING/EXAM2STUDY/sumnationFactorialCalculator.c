#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void sum(void*);
void fact(void*);

int main(int numCommands, char** commandLine)
{		
	pthread_t thread1, thread2;


	pthread_create(&thread1, NULL, sum, atoi(commandLine[1]));
	pthread_create(&thread2, NULL, fact, atoi(commandLine[1]));

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}

void sum(void* number)
{
	int sum = 0;
	for(int i = 1; i <= (int)number; i++)
	{
		sum += i;
	}
	printf("SUM: %d\n", sum);
}

void fact(void* number)
{
	int product = 1;
	for(int i = 1; i <= (int) number; i++)
	{
		product *= i;
	}
	printf("Product: %d\n", product);
}
