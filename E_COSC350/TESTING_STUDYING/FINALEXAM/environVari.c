#include <stdio.h>
extern char** environ;

char* getEnviron(char*);
void listAll();


int main()
{
	getEnviron("OLDPWD");
	return 0;
}

void listAll()
{
	for(int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

}

char* getEnviron(char* searchTerm)
{
	int isVariable = 1;
	int j;
	for(int i = 0; environ[i] != NULL; i++)
	{
		isVariable = 1;
		for(j = 0; searchTerm[j] != '\0'; j++)
		{
			if(searchTerm[j] != environ[i][j])
			{
				isVariable = 0;
				break;
			}
		}

		if(!isVariable)
			continue;

		if(environ[i][j] != '=')
		{
			printf("%c\n", environ[i][j]);
			isVariable = 0;
		}
		
		j++;

		for(int k = j; environ[i][k] != '\0'; k++)
		{
			printf("%c", environ[i][k]);
		}
		printf("\n");
		break;
	}

	if(!isVariable)
		printf("COULDN'T FIND THAT VARIABLE\n");

}

