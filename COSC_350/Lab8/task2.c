#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int* testScores;

void* fillArray();
void* clearArray();

void* minMaxCalc();
void* averageCalc();

void displayArray(int);
void copy(int*);
void sort(int*);


int main()
{

	pthread_t thread1, thread2, thread3, thread4;	
	
	if(pthread_create(&thread1, NULL, fillArray, NULL) != 0) 
	{
		printf("Thread 1 Failed");
		return -1;
	}


	pthread_join(thread1, NULL);


	if(pthread_create(&thread2, NULL, averageCalc, NULL) != 0) 
	{
		printf("Thread 2 Failed");
		return -1;
	}


	if(pthread_create(&thread3, NULL, minMaxCalc, NULL) != 0) 
	{
		printf("Thread 3 Failed");
		return -1;
	}

	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);


	if(pthread_create(&thread4, NULL, clearArray, NULL) != 0) 
	{
		printf("Thread 4 Failed");
		return -1;
	}

	pthread_join(thread4, NULL);

	return 0;
}


void displayArray(int size)
{
	for(int i = 1; i != size+1; i++)
	{
	printf("%d ",testScores[i]);
	}
	printf("\n");
}

void* clearArray()
{
	free(testScores);
	testScores = 0;
	displayArray(1);
	return (void *)testScores;
}

void* fillArray()
{
	int buff;
	int size = 0;


	testScores = (int *)malloc(sizeof(int));

	printf("type numbers in to add to array or anything else to end\n");

	while(scanf("%d", &buff) == 1 && size != 20)
	{
		size++;
		testScores = (int *)realloc(testScores, sizeof(testScores) + sizeof(int));
		testScores[size] = buff;
	}
	testScores[0] = size;

	return testScores;
}

void* averageCalc()
{
	double avg = 0;
	double median = 0;
	for(int i = 1; i < testScores[0] + 1; i++)
	{
		avg += testScores[i];
	}
	avg = avg / testScores[0];

	int sortedArray[testScores[0] + 1];

	copy(sortedArray);
	sort(sortedArray);

	if(sortedArray[0] % 2 == 0)
	{median = (sortedArray[(sortedArray[0]) / 2 + 1 ] + sortedArray[(sortedArray[0]) / 2 ]) / (double)2;}
	else
	{median = sortedArray[(sortedArray[0] + 1) / 2];}	

	printf("Average: %f Median: %f\n", avg, median);
}

void sort(int* array)
{
	int temp;
	for(int i = 0; i < array[0]; i++)
	{
		for(int j = 1; j < array[0] - i; j++)
		{
			if(array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j +1];
				array[j + 1] = temp;
			}
		}
	}
}

void copy(int * array)
{
	for(int i = 0; i < testScores[0] + 1; i++)
	{
		array[i] = testScores[i];
	}
}

void* minMaxCalc()
{

	int min = testScores[1];
	int max = testScores[1];


	for(int i = 1; testScores[0] + 1 != i; i++)
	{
		if(testScores[i] < min)
		min = testScores[i];
		if(testScores[i] > max)
		max = testScores[i];
	}


	printf("Min: %d Max: %d \n", min, max);

	return NULL;
}