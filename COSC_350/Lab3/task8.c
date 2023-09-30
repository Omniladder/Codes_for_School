#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int num_Inputs, char* FileInputs[])
{
    umask(0000);

	if(num_Inputs > 3)
	{
		printf("INPUT 2 Files as parameters");
		return 1;
	}


    
    int in = open(FileInputs[1], O_RDONLY);

	if(in == -1)
	{
		printf("Infile Failed to Open");
		return 1;
	}

    int out = open(FileInputs[2], O_WRONLY|O_CREAT, 0666);
	
    if(out == -1)
	{
		printf("outfile Failed to Open");
		return 1;
	}
   
dup2(out, 1);   
char letter[1];


while(read(in, &letter, 1) > 0)
{
printf("%ld", (long)letter[0]);
printf(" ");
}


return 0;
}
