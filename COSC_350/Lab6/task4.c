#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int string_To_Int(char*);


int main(int numInputs, char *Inputs[])
{
	if(numInputs != 5)
	{
		fprintf(stderr,"Must Pass 4 Integers 1: Child Iterations 2: Parent Iterations 3: Child Sleep 4: Parent Sleep \n");  
		exit(1);
	}

	pid_t pid;
	char *message;
	int n;
	int child_Status;

	int child_Iterations = string_To_Int(Inputs[1]);
       	int parent_Iterations = string_To_Int(Inputs[2]); 
	
	int child_Sleep = string_To_Int(Inputs[3]);
	int parent_Sleep = string_To_Int(Inputs[4]);

	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
	case -1:
		perror("fork failed");
		exit(1);
	case 0:
		message = "This is the child";
		n = child_Iterations;
		break;
	default:
		message = "This is the parent";
		n = parent_Iterations;
		break;
	}

	for(; n > 0; n--)
	{
		if(pid == 0)
		{	
			puts(message);
			sleep(child_Sleep);
		}
		else
		{
			wait(&child_Status);
			puts(message);
			sleep(parent_Sleep);
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
