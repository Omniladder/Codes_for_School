#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int convert(char);
int convIntToStr(char*, int);

int main(int numOfArgs, char* Inputs[])
{
char data[256];

if(numOfArgs < 2)
{
	printf("Please Enter a Proper Argument");
	exit(-1);
}

if(numOfArgs >= 3)
{
	printf("Please Pass in Only One Argument");
	exit(-1);
}


int file = open(Inputs[1], O_RDONLY);

int length = 0;
int num = 0;
char buff[1];


while(read(file, buff, 1) > 0)
{length++;}

char Contents[length];

lseek(file, 0, SEEK_SET);

for(int i = 0; i < length; i++)
{
	read(file, buff,1);
	Contents[i] = buff[0];
}


for(int i = 0; i < length; i++)
{
	if( convert(Contents[i]) != -1 )
	{
		num*=10;
		num += convert(Contents[i]);
	}
}

num+=10;


	convIntToStr(data, num);
	printf("%s", data);

exit(0);
}















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
return -1;//signal to output something went wrong
}
return convertedNum;//returns proper number
}

int convIntToStr(char* str, int x)
{
sprintf(str, "%d", x);
return (strlen(str));
}
