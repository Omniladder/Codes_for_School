#include <stdio.h>
#include <string.h>

extern char **environ;

int main(int numInputs, char* commandLine[])
{
	if(numInputs != 2)
	{
		printf("Proper Num inputs is 1 : search enviornmental\n");
	}

	char* searchTerm = commandLine[1];

	int searchSize = strlen(searchTerm);

	int environSize = 0;

	while (environ[environSize] != NULL)
	environSize++;

	int j = 0;


	for (int i = 0; i < environSize; i++)
	{
		for(j = 0; j < searchSize; j++)
		{

			if(environ[i][j] != searchTerm[j] || environ[i][searchSize] != '=')
			{
				break;
			}
		}


		if(j == searchSize)
		{
			for(int k = searchSize + 1; k < strlen(environ[i]); k++)
			printf("%c", environ[i][k]);
			return  0;
		}
		

	}
	printf("FAILED TO FIND TERM\n");
	return -1;
}
