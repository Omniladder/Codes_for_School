

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int string_To_Int(char*);
int get_String_Size(char*);
char* concatenate(char*, char*, char*);

int main(int numInputs, char *Inputs[])
{

	int pid = fork();
	char buff[1];


	int in = open(Inputs[1], O_RDONLY);
	int pout = creat("parent.txt", 0666);
	int cout = creat("child.txt", 0666);

while(read(in, buff, 1))
{
	if(pid != 0)
	{
		if(buff[0] - '0' < 0 || buff[0] - '0' > 9)
		write(pout, buff, 1);
	}
	else
	{
		if(buff[0] - '0' >= 0 && buff[0] - '0' <= 9)
		write(cout, buff, 1);
	}
}
	exit(0);
}

char* concatenate(char* string1, char* string2, char* newString)
{
	int size= 0;
	int i;
	for(i = 0; string1[i] != '\0'; i++)
	{
	size++;
	newString[i] = string1[i];
	}

	for(i = 0; string2[i] != '\0'; i++)
	{
	newString[size + i] = string2[i];
	}

	newString[size + i] = '\0';


	return newString;
}

int get_String_Size(char* string)
{
	int i = 0;
	for(; string[i] != '\0'; i++){}
	return i;
}

int string_To_Int(char* string)
{
	int result = 0;	
	
	for(int i = 0; string[i] != '\0'; ++i)
	{
		if(string[i] < '0' || string[i] > '9')
		{
			fprintf(stderr, "NON INTEGER INPUTTED");
			exit(-1);
		}
		else
		result = result * 10 + string[i] - '0';
		
	}
	
	return result;		
}
