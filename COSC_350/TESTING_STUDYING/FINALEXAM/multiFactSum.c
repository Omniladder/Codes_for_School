#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* sum(void* number) //REMMEBER * after void MUST HAVE RETURN TYPE
{
	int sum = 0;
	int num = (int) number; //Remember to Cast here

	for(int i = 1; i <= num; i++)
		sum+=i;

	printf("THE SUM IS : %d\n", sum);
	return NULL; //RETURN NULL
}

void* fact(void* number)
{
	int fact = 1;
	int num = (int) number;
	for(int i = 1; i <= num; i++)
	{
		fact *= i;
	}

	printf("The output of Factorial is : %d\n", fact);
	return NULL;
}

int main(int numberArgs, char** commandLine)
{
	if(numberArgs != 2)
	{
		printf("INVALID NUMBER OF  ARGUMENTS\n");
		exit(-1);

	}

	int number = atoi(commandLine[1]);

	pthread_t sumThread, factThread;
	
	pthread_create(&sumThread, NULL, sum, (void*)number);	//REMEMBER &
	pthread_create(&factThread, NULL, fact, (void*)number);	//REMEMBER &


	pthread_join(sumThread, NULL);
	pthread_join(factThread, NULL);
	exit(0);
}
