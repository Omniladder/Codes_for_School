#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int num_Inputs, char* FileInputs[])
{
    umask(0000);


	if(num_Inputs < 3)
	{
		fprintf(stderr, "INPUT 2 Files as parameters \n");
		return 1;
	}


    
    int in = open(FileInputs[1], O_RDONLY);

	if(in == -1)
	{
		fprintf(stderr, "Infile Failed to Open \n");
		return 1;
	}

    int out = open(FileInputs[2], O_WRONLY|O_CREAT, 0666);
	
    if(out == -1)
	{
		fprintf(stderr, "outfile Failed to Open \n");
		return 1;
	}
   
dup2(out, 1);   
char letter[1];


while(read(in, &letter, 1) > 0)
{
printf("%03ld", (long)letter[0]);
}


return 0;
}
