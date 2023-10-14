
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


char* concatenate(const char*, const char*, char*);//CONCATENATES WORDS TOGETHER
void copyFile(int, int); //TAKES TWO FILE NAMES FIRST BEING INPUT SECOND BEING OUTPUT AND COPIES DATA OVER 


int main()
{
 	const char *home = getenv("HOME"); // Get the home directory path

	umask(0000);//SETS TO DEFAULT MASK

    if (home == NULL) {//IF HOME FAILS TELLS USER
        printf("FAILED TO FIND HOME");
	exit (-1);
	}

	    char buff[500]; // A buffer to hold the directory path
		char buff2[500];//HOLDS OUT OF THE LINK

        // Combine the home directory path with the desired directory name

	if(mkdir(concatenate(home, "/Dir1", buff), 0777) < 0)//MAKES DIR1 DIRECTORY
	{
	perror("FAILED TO MAKE DIRECTORY");
	return -1;
	}

	if(mkdir(concatenate(home, "/Dir2", buff), 0777) < 0)//MAKES DIR2 DIRECTORY
	{
	perror("FAILED TO MAKE DIRECTORY");
	return -1;
	}
	
	
	if(mkdir(concatenate(home, "/Dir2/Dir21", buff), 0777) < 0)//MAKES DIR21 DIRECTORY
	{
	perror("FAILED TO MAKE DIRECTORY");
	return -1;
	}

	int inFile = open("hello", O_RDONLY);//OPENS FILE HELLO FOR COPYING
	
	if(inFile < 0)
	{
	perror("FAILED TO OPEN  INPUT");
	return -1;
	}

	int outFile = creat(concatenate(home, "/Dir2/Dir21/hello", buff), 0777);//CREATES FILE TO COPY TO

	

	

	if(outFile < 0)//CHECKS IF OUTFILE EXISTS
	{
	perror("FAILED TO CREATE OUT FILE");
	return -1;
	}


	copyFile(inFile, outFile);//COPIES FILE TO NEW LOCATION

	close(inFile);
	close(outFile);//CLOSES FILES
 
	if(symlink(concatenate(home, "/Dir2/Dir21", buff), concatenate(home, "/Dir1/toDir21", buff2)) < 0) //MAKES SURE SYMBOLI LINK PROPERLY CREATED
	{
	perror("Symbolic Link Failed");
	exit (-1);
	}

	if(symlink(concatenate(home, "/Dir2/Dir21/hello", buff), concatenate(home, "/Dir1/tohello", buff2)) < 0)//MAKES AND CHECKS TO MAKE SURE PROPER SYMBOLIC LINK CREATION
	{
	perror("SYNBOLIC LINK FAILED");
	exit(-1);
	}
}


char* concatenate(const char* string1, const char* string2, char* newString)
{
	sprintf(newString, "%s%s", string1, string2);//concatenates the string
	return newString;//returns string
}

void copyFile(int inFile, int outFile)//COPIES FILE
{
	char buff[1];//BUFFER TO HOLD DATA
	while(read(inFile, buff, 1 ) >= 1)//READS IN DATA 1 BIT AT TIME
	{
	write(outFile, buff, 1);//WRITES BIT OUT
	}
}
