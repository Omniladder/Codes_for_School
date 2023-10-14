
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


char* concatenate(const char*, const char*, char*);
void copyFile(int, int); //TAKES TWO FILE NAMES FIRST BEING INPUT SECOND BEING OUTPUT AND COPIES DATA OVER 


int main()
{
 	const char *home = getenv("HOME"); // Get the home directory path

	umask(0000);

    if (home == NULL) {
        printf("FAILED TO FIND HOME");
	exit (-1);
	}

	    char buff[500]; // A buffer to hold the directory path

        // Combine the home directory path with the desired directory name

	mkdir(concatenate(home, "/Dir1", buff), 0777);
	mkdir(concatenate(home, "/Dir2", buff), 0777);
	mkdir(concatenate(home, "/Dir2/Dir21", buff), 0777);

	int inFile = open("hello", O_RDONLY);
	int outFile = creat(concatenate(home, "/Dir2/Dir21/hello", buff), 0777);


	copyFile(inFile, outFile);

	close(inFile);
	close(outFile);



	if(symlink(concatenate(home, "/Dir1/toDir21", buff), concatenate(home, "/Dir2/Dir21", buff)) < 0)
	{
	perror("Symbolic Link Failed");
	exit (-1);
	}

	if(symlink(concatenate(home, "/Dir1/tohello", buff), concatenate(home, "/Dir2/Dir21/hello", buff)) < 0)
	{
	perror("SYNBOLIC LINK FAILED");
	exit(-1);
	}
}


char* concatenate(const char* string1, const char* string2, char* newString)
{
	sprintf(newString, "%s%s", string1, string2);
	return newString;
}

void copyFile(int inFile, int outFile)
{
	char buff[1];
	while(read(inFile, buff, 1 ) >= 1)
	{
	write(outFile, buff, 1);
	}
}
