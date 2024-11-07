#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t child = fork();

	if(child == 0)
	{
		while(1){;}
	}
	else
	{

		_exit(0);
	}

}
