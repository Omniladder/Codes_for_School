#include <stdio.h>
int st_to_int(char*);

int main(int argsNum, char* Inputs[])
{
	if(argsNum <= 1)
	{printf("PUT IN 1 OR MORE INTEGERS"); return(-1);}
	
	int sum = 0;
	
	for(int i = 1; i != argsNum; i++)
	if(st_to_int(Inputs[i]) % 2 == 0)
	sum+=st_to_int(Inputs[i]);
	
	printf("SUM OF INTS IS %d", sum);
}

int st_to_int(char* str)
{
	int start = 0, sum = 0;
	
	if(str[0] == '-')
	start = 1;

	for (int i = start; str[i] != '\0'; i++)
	sum = sum * 10 + (str[i] - '0');
	
	if(start)
	sum *= -1;

	return sum;
}
