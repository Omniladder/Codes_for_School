
#include <utmp.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int openUtmpFile();

int main(int numInputs, char *Inputs[])
{
	int numUsers = 0;
	int tmp = openUtmpFile();

	struct utmp userData;	
	
	
	while(read(tmp, &userData, sizeof(userData)) >= 1)
	{
		if (userData.ut_type == USER_PROCESS) 
		{
			printf("%.*s\n" , (int)(sizeof userData.ut_user), userData.ut_user);
        		numUsers++;
		}
	}
	
	printf("NUMBER OF LOGGED IN USERS IS %d\n", numUsers);
}



int openUtmpFile()
{

	int tmpFile = open("/var/run/utmp", O_RDONLY);
	if(tmpFile < 0)
	{
		perror("FILE FAILED TO OPEN");
		exit(-1);
	}
	else
	{
		return tmpFile;
	}
}
