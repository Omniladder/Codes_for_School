
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int convert(char letter)
{
int convertedNum;
if(letter == '0')
{convertedNum = 0;}
else  if(letter == '1')
{convertedNum = 1;}
else  if(letter == '2')
{convertedNum = 2;}
else  if(letter == '3')
{convertedNum = 3;}
else  if(letter == '4')
{convertedNum = 4;}
else  if(letter == '5')
{convertedNum = 5;}
else  if(letter == '6')
{convertedNum = 6;}
else  if(letter == '7')
{convertedNum = 7;}
else  if(letter == '8')
{convertedNum = 8;}
else  if(letter == '9')
{convertedNum = 9;}
else
{
printf ("FILE MUST CONTAIN ONLY NUMBERS \n"); 
return -1;
}
return convertedNum;
}


int main(int num_Inputs, char* FileInputs[])
{
    umask(0000);

	if(num_Inputs > 3)
	{
		printf(stderr,"INPUT 2 Files as parameters");
		return 1;
	}


    
    int in = open(FileInputs[1], O_RDONLY);

	if(in == -1)
	{
		fprintf(stderr,"Infile Failed to Open");
		return 1;
	}

    int out = open(FileInputs[2], O_WRONLY|O_CREAT, 0666);
	
    if(out == -1)
	{
		fprintf(stderr,"outfile Failed to Open");
		return 1;
	}
   
dup2(out, 1);   
char letter[1];

int sum = 0;
int placeValue = 1;

while(read(in, &letter, 1) > 0)
{
	for(int i = 0; i < 3; i++)
	{
		sum += convert(letter[0]) * placeValue;
		placeValue *= 10;
		read(in, &letter, 1);
	}
	printf("%c", (char) sum);
	placeValue = 1;
	sum = 0;
}


return 0;
}
