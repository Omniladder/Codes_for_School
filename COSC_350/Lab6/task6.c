

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int numInputs, char *Inputs[])
{

	char buff[1];


	int in = open(Inputs[1], O_RDONLY);
	int pout = creat("parent.txt", 0666);
	int cout = creat("child.txt", 0666);
	
	int loc = 0;

	int pid = fork();


while(pread(in, buff, 1, loc) >= 1)
{
	if(pid == 0)
	{
		if(buff[0] - '0' < 0 || buff[0] - '0' > 9)
		{
		write(cout, buff, 1);
		}
		loc++;
	}

	if(pid != 0)
	{
		if(buff[0] - '0' >= 0 && buff[0] - '0' <= 9)
		{
		write(pout, buff, 1);
		}
		loc++;
	}

	printf("%d ", loc);

}
	exit(0);
}
