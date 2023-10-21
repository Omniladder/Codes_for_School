
#include <utmp.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int openUtmp();

int main(int numInputs, char *Inputs[])
{
	int in = openUtmp();

	struct utmp user_Data;
	int count = 0;
	while(read(in, &user_Data, sizeof(user_Data)) >= 1)
	{
	if (user_Data.ut_type == USER_PROCESS) 
	{
		printf("%s\n", user_Data.ut_user);
        	count++;
	}
	}
	printf("NUMBER OF LOGGED IN USERS IS %d\n", count);
}



int openUtmp()
{

	int in = open("/var/run/utmp", O_RDONLY);
	if(in < 0)
	{
		perror("FILE FAILED TO OPEN");
		exit(-1);
	}
	else
	{
		return in;
	}
}
