
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int convert(char letter)//converts chars to ints
{
int convertedNum;//holds answer
if(letter == '0')//checks if 0
{convertedNum = 0;}//sets to 0
else  if(letter == '1')//checks if 1
{convertedNum = 1;}//sets to 1
else  if(letter == '2')//checks for 2
{convertedNum = 2;}//sets to 2
else  if(letter == '3')//checks for 3
{convertedNum = 3;}//sets to 3
else  if(letter == '4')//checks for 4
{convertedNum = 4;}//sets to 4
else  if(letter == '5')//checks 5
{convertedNum = 5;}//sets 5
else  if(letter == '6')//checks 6
{convertedNum = 6;}//sets 6
else  if(letter == '7')//checks 7
{convertedNum = 7;}//sets 7
else  if(letter == '8')//checks 8
{convertedNum = 8;}//sets 8
else  if(letter == '9')//checks 9
{convertedNum = 9;}//sets 9
else
{
fprintf (stderr, "FILE MUST CONTAIN ONLY NUMBERS \n"); //if user didn't input a number
fprintf(stderr, "_%c_", letter);
return -1;//signal to output something went wrong
}
return convertedNum;//returns proper number
}


int main(int num_Inputs, char* FileInputs[])//takes in parameters
{
    umask(0000); //sets permissions to default

	if(num_Inputs < 3)//checks to make sure proper number of inputs were inputted
	{
		fprintf(stderr,"INPUT 2 Files as parameters \n");//tells user what went wrong
		return 1;//exits
	}


    
    int in = open(FileInputs[1], O_RDONLY); //opens file designed for input

	if(in == -1)// checks to make sure that the file openned
	{
		fprintf(stderr,"Infile Failed to Open \n");//prompts user
		return 1;//exits 
	}

    int out = open(FileInputs[2], O_WRONLY|O_CREAT, 0666); //opens output file
	
    if(out == -1)//checks to make sure out file oppened
	{
		fprintf(stderr,"outfile Failed to Open \n");//prompts user
		return 1;//exits
	}
   
dup2(out, 1);   //sets output to std out
char letter[3];//creates a 3 chat buffer

int sum = 0;//holds the full size ASCII number

while(read(in, &letter, 3) > 2) //reads in 3 intergers
{
	if(letter !=  "\n")
	{
	for(int i = 0; i < 3; i++)//used to combine 3 integers into 1
	{

		sum *= 10;//shifts all of sum over one so next charcter can take ones place
		sum += convert(letter[i]);//sets last charcter to ones place
	}
	printf("%c", (char) sum);//converts num to char and writes it in
	sum = 0;//resets sum for next number
	}
	}


return 0;//ends code
}
