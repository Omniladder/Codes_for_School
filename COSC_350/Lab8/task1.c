#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void* factorial(void*);
void* sumnation(void*);

int main(int numInputs, char* commandLine[])
{
	pthread_t factThread, sumThread;

	int inputParameters[1];
	inputParameters[0] = atoi(commandLine[1]);

	if(pthread_create(&factThread, NULL, factorial, inputParameters) != 0) 
	{
		printf("Thread 1 Failed");
		return -1;
	}

	if(pthread_create(&sumThread, NULL, sumnation, inputParameters) != 0)
	{
		printf("Thread 2 Failed");
		return -1;
	}

	void* sumBuffer;
	void* factBuffer;



	pthread_join(sumThread, &sumBuffer);	
	pthread_join(factThread, &factBuffer);	

	
	printf("Final Sum Result %d\n", (int)(sumBuffer));
	printf("Final Factorial Result %d\n", (int)(factBuffer));

}


void* factorial(void* inputtedNum)
{
	int sum;
	sum = 1;
	for(int i = 1; i <= *(int *)inputtedNum; i++)
	{
		sum *= i;
	}
	return (void *)sum;
}

void* sumnation(void* num) 
{
	return (void *)(((* (int*) num + 1) * ((int)(*(int*)num) / 2)) + ((*(int*)num % 2) * (((*(int*)num + 1) / 2)))); 
}




