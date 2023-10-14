#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>



char* concatenate(const char*, const char*, char*);

int main(int numOfArgs, char* Inputs[])
{
	if(numOfArgs < 2) //CHECKS TO MAKE SURE PROPER NUMBER OF INPUTS WERE INPUTTED
	{
	printf("PLEASE ENTER 2 INPUTS FILE NAME AND DIRECTORY\n");
	return (-1);
	}

	if(access(Inputs[1], F_OK) != 0) //Makes sure input file exists
	{
	printf("FILE %s IS NOT ACCESSABLE OR DOES NOT EXISTS\n", Inputs[1]);
	return (-1);
	}


	struct stat fileStat;

	if(stat(Inputs[2], &fileStat) != 0)
	{
	perror("Couldnt Gather information on Output Directory");
	return -1;
	}

	char buf [strlen(Inputs[1]) + strlen(Inputs[2]) + 1];

	if(S_ISDIR(fileStat.st_mode))
	{
		concatenate(Inputs[2], Inputs[1], buf);
	}
	else
	{
	sprintf(buf, "%s", Inputs[1]);
	}	
	
	
	if(link(Inputs[1], buf) < 0 ) //creates link and makes sure its linked properly
	{
	perror("LINK FAILED: "); //Teels user what went wrong
	return (-1);
	}


	unlink(Inputs[1]);




	

}


char* concatenate(const char* string1, const char* string2, char* newString)
{
	sprintf(newString, "%s%s", string1, string2);
	return newString;
}
