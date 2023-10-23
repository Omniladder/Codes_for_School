
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

char* mygetenv(char* searchTerm); //prototypes function

extern char **environ; //gets in enviornment variables
static char output[500];//used to store final result

int main()
{
	char* result = mygetenv("PWD");//calls functions and stores result
	if(result != NULL) //Checks if Input had been found
	{
		printf("%s", result);//outputs location
	}
}

char* mygetenv(char* searchTerm)
{
	int searchTermSize = strlen(searchTerm); //stores size of search term
	int letterIndex = 0;//used to go through each letter of enviornment variable



	for(int variableIndex = 0; environ[variableIndex] != NULL; variableIndex++) //loops through all enviornmental variables
	{
	
		while(letterIndex < searchTermSize) //loops through every element of the term being ssearched for to figure out if its been found
		{
			if(environ[variableIndex][letterIndex] != searchTerm[letterIndex])//checks if any letters dont match if they dont breaks
			{
				break;	//breaks out so that letterIndex would activate next one
			}
			letterIndex++;//increments to next index
		}
		
		
		
		if(letterIndex == searchTermSize && environ[variableIndex][searchTermSize] == '=') //checks if they were equal and that we hit end of word
		{
			strcpy(output, environ[variableIndex] + searchTermSize + 1);//sets output to variable
			return strcat(output, "\n"); //adds \n to end and returns
		}
		
		letterIndex = 0; //starts letter index back at 0 for next one

	}
	
	printf("FAILED TO FIND VARIABLE NAMED %s\n", searchTerm); //gives error if couldnt find term
	
	return (NULL);//used to tell if error happened
}

