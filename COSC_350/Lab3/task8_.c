#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int num_Inputs, char* FileInputs[]) //takes in the parameters
{
    umask(0000); // sets permissions to accept whatever i put in


	if(num_Inputs < 3)//checks to make sure I inputted enough files
	{
		fprintf(stderr, "INPUT 2 Files as parameters \n");
		return 1;
	}


    
    int in = open(FileInputs[1], O_RDONLY);//opens input file

	if(in == -1)//errors if file didnt open
	{
		fprintf(stderr, "Infile Failed to Open \n");//explains error to user
		return 1;//exits
	}

    int out = open(FileInputs[2], O_WRONLY|O_CREAT, 0666);//creates file with proper permission
	
    if(out == -1)//checks to make sure that the file has opened
	{
		fprintf(stderr, "outfile Failed to Open \n");//tells user what happened
		return 1;//exits program
	}
   
dup2(out, 1);   //sets out file as output to stdin
char letter[1];//buffer to hold data


while(read(in, &letter, 1) > 0)//reads in every char
{
printf("%03ld", (long)letter[0]);//convers to ascii than pads to 3 digits in order for it to be standardozed to read in later
}


return 0;//leaves program
}
