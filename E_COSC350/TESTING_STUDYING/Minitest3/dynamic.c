#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(unsigned char* array, int size);
void print(unsigned char* array, int size);

int main()
{
	unsigned char* array = (unsigned char *)malloc(3 * sizeof(unsigned char));
	fill(array, 3);
	print(array, 3);
	array = (unsigned char*)realloc(array, 7 * sizeof(unsigned char));
	fill(array, 7);
	print(array, 7);
	array = (unsigned char*)realloc(array, 3 * sizeof(unsigned char));
	array = (unsigned char*)realloc(array, 5 * sizeof(unsigned char));
	print(array, 5);
	free(array);
}
void fill(unsigned char* array, int size)
{
	for(int i = 0; i < size; i++)
	{
	*(array + i) = i;
	}
}




void print(unsigned char* array, int size)
{
	for(int i = 0; i < size; i++)\
	{
	printf("%d", *(array + i));
	}
	printf("\n");
}
