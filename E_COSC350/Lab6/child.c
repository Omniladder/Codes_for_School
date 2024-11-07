

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
	if(numInputs != 3)
	{
		fprintf(stderr,"INPUT FAILURE IN CHILD \n");
		exit(1);
	}

	char *message = Inputs[0];
	int n;

       	int Iterations = string_To_Int(Inputs[1]); 
	n=Iterations;
	
	int Sleep = string_To_Int(Inputs[2]);





	for(; n > 0; n--)
	{
		printf("%s PID IS : %d\n", message, getpid());
		sleep(Sleep);
	}

	return(37);
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
