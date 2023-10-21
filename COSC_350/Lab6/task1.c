
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

char* mygetenv(char*);

extern char **environ;
static char output[500];

int main()
{
printf("%s\n", mygetenv("PATH"));
}

char* mygetenv(char* varName)
{
	int env_Size = strlen(varName);
	int j = 0;



	for(int i = 0; environ[i] != NULL; i++)
	{
		for(j = 0; j < env_Size; j++)
		{
			if(environ[i][j] != varName[j])
			{
			break;	
			}
		}

		if(j == env_Size && environ[i][env_Size] == '=')
		{
			for(j = env_Size; j < strlen(environ[i]) - 1; j++)
			{
			output[j - env_Size] = environ[i][j + 1];
			}
			output[j] =  '\n';
			return output;

		}

	}
	
	puts("FAILED TO FIND VARIABLE");
	exit (-1);
}

