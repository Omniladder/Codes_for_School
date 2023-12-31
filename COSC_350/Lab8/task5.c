#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate(const char*, const char*, char*);

int main(int commandSize, char** commandLine)
{
	
	char bashCommand[256];
	char bashOutput[BUFSIZ];
	for(int i = 1; i < commandSize; i++)
	{
		concatenate(bashCommand, commandLine[i], bashCommand);
	}

	for(int i = 1; i < strlen(bashCommand); i++)
	{
		bashCommand[i - 1] = bashCommand[i];
	}
	
	bashCommand[strlen(bashCommand) - 1] = ' ';

	FILE*	child = popen(bashCommand,"r"); /* creat a pipe */


	while(fgets(bashOutput, BUFSIZ, child))
	{
       printf("%s", bashOutput);
    }

	pclose(child);
	exit(0);
}


char* concatenate(const char* string1, const char* string2, char* newString)
{
	sprintf(newString, "%s %s", string1, string2);//concatenates the string
	return newString;//returns string
}
