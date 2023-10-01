

//Fuck You Kyle


#include <stdio.h>
#include <string.h>

int convert(char letter)//used to convert int to char
{
int convertedNum;//holds number being converted
if(letter == '0')//checks 0
{convertedNum = 0;}//sets 0
else  if(letter == '1')//checks 1
{convertedNum = 1;}//sets 1
else  if(letter == '2')//checks 2
{convertedNum = 2;}//sets 2
else  if(letter == '3')//checks 3
{convertedNum = 3;}//sets 3
else  if(letter == '4')//checks 4
{convertedNum = 4;}//sets 4
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
fprintf (stderr, "ENTER NUMBERS IN ONLY \n"); //outputs error if incorrect output
return -1; //gives sign something gone wrong
}
return convertedNum;//outputs number
}


int main (int numOfNumbers, char* fullNum[]) //takes in parameters
{
int stringSize; //will hold size of string
int sum = 0;//used for calculating sum


if(numOfNumbers <= 1)//input validates to make sure input was inputted
{
fprintf(stderr, "MUST INPUT AT LEAST 1 NUMBER PARAMETER \n");//outputs error message
return -1;//exits
}


for (int i = 1; i < numOfNumbers; i++)//loops through every number in index
{
    stringSize = strlen(fullNum[i]);//holds number of numbers
    for (int j = 0; j < stringSize; j++)//runs through every digit of that number
    {
        if (convert(fullNum[i][j]) != -1)//makes sure number properly converted
            sum += convert(fullNum[i][j]);//adds to sum
        else
            return -1;//exits if number not inputted
}


}

printf("your final sum is %d\n",sum); //returns answer

return 0;//exits program
}
