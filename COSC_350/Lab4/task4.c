

<<<<<<< HEAD

int main()
{

=======
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int numOfArgs, char* Inputs[])
{
	if(numOfArgs < 2)
	{
	printf("PLEASE ENTER 2 INPUTS FILE NAME AND DIRECTORY\n");
	return (-1);
	}

	if(access(Inputs[1], F_OK) != 0)
	{
	printf("FILE %s IS NOT ACCESSABLE OR DOES NOT EXISTS\n", Inputs[1]);
	return (-1);
	}

	if(link(Inputs[1], Inputs[2]) < 0 )
	{
	printf("LINK FAILED \n");
	return (-1);
	}

	int exists = 1;

	if(access(Inputs[2], F_OK) != 0)
	{
	creat(Inputs[2], 0666);
	exists = 0;
	}

	




	if(unlink(Inputs[2] ) < 0)
	{
	printf("UNLINKING FAILED\n");
	return -1;
	}
>>>>>>> 63881e9f9ff8b01365bd82cf1bd29bb3a7182cd3

}
