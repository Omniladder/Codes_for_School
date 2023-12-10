#include <stdlib.h>
#include <stdio.h>

int myatoi(char*);

int main()
{
	char* string = "1234567890";
	char* negative = "-69420";
	char* words = "BAD NUMBERS";

	printf("IN ORDER: %d\n", myatoi(string));
	printf("Negative: %d\n", myatoi(negative));
	printf("WORDS: %d\n", myatoi(words));
	
	return 0;
}



int myatoi(char* string)
{
	int numberOutput = 0;
	int negativeSign = 1;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if(i == 0 && string[i] == '-')
		{
			negativeSign *= -1;
		}
		else{
		if(string[i] - '0' >= 0 && string[i] - '0' <= 9)
		{
			numberOutput = numberOutput * 10 + string[i] - '0';
		}
		else
		{
			printf("::INVALID INPUT::\n");
			exit(-1);
		}
		}
	}

	return numberOutput * negativeSign;

}
