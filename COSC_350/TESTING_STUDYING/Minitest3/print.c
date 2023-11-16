#include <stdio.h>

void print(char*);

int main()
{
	print("WORLD HELLO");
}

void print(char* string)
{
	for(int i =0; string[i] != '\0'; i++)
	{
		printf("%c", string[i]);
	}
}
