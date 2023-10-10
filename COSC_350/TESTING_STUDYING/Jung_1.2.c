#include <stdio.h>


int st_to_int(char*);
char* int_to_str(char*, int);


int main()
{
char buff[256];
printf("%d\n", st_to_int("1234"));
printf("%s\n", int_to_str(buff, 1234));
}


int st_to_int(char* str)
{
	int ans = 0;
	for(int i = 0;  str[i] != '\0'; i++)
	ans = ans * 10 + str[i] - '0';
	return ans;

}


char* int_to_str(char* string, int num)
{
	sprintf(string, "%d", num);
	return string;
}
