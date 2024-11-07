#include <stdio.h>
#include <stdlib.h>

struct worker{
	int ID;
	char firstName[25];
	char lastName[25];
};

int main(int numArguments, char** commandLine)
{
	

	if(numArguments != 2)
	{
		printf("ENTER IN 1 ARGUMENT FOR HOW MANY WORKERS YOU WANT\n");
		exit(-1);
	}
	int arraySize = atoi(commandLine[1]);

	struct worker* workerArray = (struct worker*)calloc(arraySize, sizeof(struct worker)); //REMEMBER YOUR STRUCTS

	if(workerArray == NULL)
	{
		printf("SOMETHIG DARN DIDDLY BROKE DAMN IT\n");
		return -1;
	}

	for(int i = 0; i < arraySize; i++)
	{
		printf("Input Worker %d First Name\n", i + 1);
		scanf("%s", workerArray[i].firstName);

		printf("Input Worker %d Last Name\n", i + 1);
		scanf("%s", workerArray[i].lastName);

		printf("Input Worker %d ID\n", i + 1);
		scanf("%d", &workerArray[i].ID); //you need to reference as it has to be a pointer this is the only one that needs a pointer since its and int and the other are string arrays which are already pointers
	}

	for(int i = 0; i < arraySize; i++)
	{
		printf("WORKER: FIRST NAME: %s \t LAST NAME: %s \t ID: %d\n\n", workerArray[i].firstName, workerArray[i].lastName, workerArray[i].ID);
	}

	free(workerArray); //REMEMBER FREE

	return -1;
}
