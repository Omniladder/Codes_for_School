#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>



char* concatenate(const char*, const char*, char*);//USED TO CONCATENATE STRINGS TOGETHER

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


	struct stat fileStat;//USED TO STORE DATA ON INPUTTED FILE

	stat(Inputs[2], &fileStat);//USED TO STORE DATA ON IF THE INPUTTED FILE IS DIRECTORY OR NOT

	char buf [strlen(Inputs[1]) + strlen(Inputs[2])];//USED TO STORE LOCATION

	if(S_ISDIR(fileStat.st_mode))//CHECKS IF DIRECTORY
	{
		concatenate(Inputs[2], Inputs[1], buf);//IF DIRECTORY CREATES LOCATION OF WHAT NEW FILE WILL BE
	}
	else
	{
	sprintf(buf, "%s", Inputs[2]);//SETS BUFFER TO JUST INPUT AS FILE LOCATION IS ALREADY SET UP
	}	


	
	if(link(Inputs[1], buf) < 0 ) //creates link and makes sure its linked properly
	{
	perror("LINK FAILED: "); //Teels user what went wrong
	return (-1);
	}


	unlink(Inputs[1]);//DELETES FILE ORIGINAL LOCATION
}


char* concatenate(const char* string1, const char* string2, char* newString)//USED TO CONCATENATE FILES
{
	sprintf(newString, "%s%s", string1, string2);//CONCATESNATES STRING
	return newString;//RETURNS SAID STRING
}
