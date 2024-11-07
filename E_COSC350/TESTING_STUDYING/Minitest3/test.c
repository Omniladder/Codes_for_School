#include <stdio.h>

int main()
{
	typedef struct {
		char text[20];
	}test;

	test tmp;

	printf("gimme chocolate");
	scanf("%s", tmp.text);

	printf("%s", tmp.text);

	return 0;
}
