#include <stdlib.h>
#include <stdio.h>

int main(int numInputs, char** commandLine)
{
	if(numInputs != 2) //MAKES SURE TO INPUT VALIDATE SILLY ME I FORGOT 
	{
		printf("MAKE SURE TO INPUT ONLY 1 INTERGER NO MORE OR LESS\n");
		exit(-1);
	}

	char* dynamCharArray = 	(char *)malloc(sizeof(char) * (atoi(commandLine[1]) + 1)); // NEEDS + 1 because the alst element is the \0 REMEMBER atoi

	printf("INPUT A STRING SMALLER THAN THE INPUTTED COMMAND LINES\n");

	scanf("%s", dynamCharArray);

	dynamCharArray[atoi(commandLine[1])] = '\0';

	printf("YOU INPUTTED: %s\n", dynamCharArray);

	exit(-1);

}
