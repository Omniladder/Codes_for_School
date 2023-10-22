#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int string_To_Int(char*);	

int main(int numInputs, char *commandLine[])
{
	if(numInputs != 5)
	{
		fprintf(stderr,"Must Pass 4 Integers 1: Child Iterations 2: Parent Iterations 3: Child Sleep 4: Parent Sleep \numberIterations");
		exit(1);
	}

	pid_t processID;
	char *message;
	int numberIterations;

	int childIterations = string_To_Int(commandLine[1]);
       	int parentIterations = string_To_Int(commandLine[2]); 
	
	int childSleep = string_To_Int(commandLine[3]);
	int parentSleep = string_To_Int(commandLine[4]);

	printf("fork program starting\n");
	processID = fork();
	
	
	switch(processID)
	{
	
	case -1:
		perror("fork failed");
		exit(1);
		
	case 0:
		message = "This is the child";
		numberIterations = childIterations;
		break;
		
	default:
		message = "This is the parent";
		numberIterations = parentIterations;
		break;
	}

	for(; numberIterations > 0; numberIterations--)
	{
		if(processID == 0)
		{	
			puts(message);
			sleep(childSleep);
		}
		else
		{
			puts(message);
			sleep(parentSleep);
		}
	}
	
	exit(0);
}

int string_To_Int(char* string)
{
	int result = 0;	
	
	for(int i = 0; string[i] != '\0'; ++i)
	{
		if(string[i] < '0' || string[i] > '9')
		{
			fprintf(stderr, "NON INTEGER INPUTTED");
			exit(-1);
		}
		else
		result = result * 10 + string[i] - '0';
		
	}
	
	return result;		
}
