
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int st_to_int(char*);

int main(int numOfArgs, char* Inputs[])
{
	if(numOfArgs < 2)
	{
	printf("NO INTEGERS WERE ENTERED\n");
	return -1;
	}

	int sum = 0;

	for(int i = 1; i < numOfArgs; i++)
	{
		if(st_to_int(Inputs[i]) == -1)
		{
		printf("NON INTEGER INPUTTED");
		return -1;
		}

		if(st_to_int(Inputs[i]) % 2 == 0)
		sum += st_to_int(Inputs[i]);
	}

	printf("SUM OF EVEN NUMBERS IS %d", sum);	

}

int st_to_int(char* string)
{
	int num = 0;
	for(int i =0; string[i] != '\0'; i++)
	{
		if(string[i] - '0' >= 0 && string[i] - '0' < 10)
		{
		num = num * 10 + string[i] - '0';
		}
		else
		{
		return -1;
		}
	}
	return num;
}
