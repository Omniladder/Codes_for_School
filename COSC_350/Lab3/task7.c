



#include <stdio.h>
#include <string.h>

int convert(char letter)//used to convert int to char
{
int convertedNum;//holds number being converted
if(letter == '0')//checks 0
{convertedNum = 0;}//sets 0
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
printf ("ENTER NUMBERS IN ONLY \n"); 
return -1;
}
return convertedNum;
}


int main (int numOfNumbers, char* fullNum[])
{
int stringSize;
int sum = 0;


if(numOfNumbers <= 1)
{
printf("MUST INPUT AT LEAST 1 NUMBER PARAMETER \n");
return -1;
}


for (int i = 1; i < numOfNumbers; i++)
{
    stringSize = strlen(fullNum[i]);
    for (int j = 0; j < stringSize; j++)
    {
        if (convert(fullNum[i][j]) != -1)
            sum += convert(fullNum[i][j]);
        else
            return -1;
}


}

printf("your final sum is %d\n",sum);

}
