
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int string_To_Int(char*);
int get_String_Size(char*);
char* concatenate(char*, char*, char*);

int main(int numInputs, char *Inputs[])
{
	if(numInputs != 5)
	{
		fprintf(stderr,"Must Pass 4 Integers 1: Child Iterations 2: Parent Iterations 3: Child Sleep 4: Parent Sleep \n");
		exit(1);
	}

	char *message;
	int n;

	int pid = fork();
       	int Iterations = string_To_Int(Inputs[2]); 
	n=Iterations;
	
	int child_status;

	int Sleep = string_To_Int(Inputs[4]);


	char path[get_String_Size(getenv("PWD")) + get_String_Size("/child")];


	if(pid == 0)
	{
		printf("child program starting\n");
		if (execl(concatenate(getenv("PWD"), "/child", path), "This is the Child", Inputs[1], Inputs[3], NULL) == -1)
		{	
			perror("exec failed");
			exit(1);
		}
	}
	else
	{
	message = "This is the parent";
	for(; n > 0; n--)
	{
		wait(&child_status);
		printf("%s PID IS : %d\n", message, getpid());
		sleep(Sleep);
	}
	}
	exit(0);
}

char* concatenate(char* string1, char* string2, char* newString)
{
	int size= 0;
	int i;
	for(i = 0; string1[i] != '\0'; i++)
	{
	size++;
	newString[i] = string1[i];
	}

	for(i = 0; string2[i] != '\0'; i++)
	{
	newString[size + i] = string2[i];
	}

	newString[size + i] = '\0';


	return newString;
}

int get_String_Size(char* string)
{
	int i = 0;
	for(; string[i] != '\0'; i++){}
	return i;
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
