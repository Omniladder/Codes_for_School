#include <stdio.h>
#include <stdlib.h>

struct person
{
	int personID;
	char firstName[30];
	char lastName[30];
};

int main(int numInputs, char* commandLine[])
{
	int dataSize;

	printf("Input Struct Size\n");
	if(scanf("%d", &dataSize) < 0)
	{perror("FAILED TO READ INTEGER");}	
	
	struct person* Dustin = (struct person*) malloc(dataSize);

	printf("\nINPUT FIRST NAME\n");
	scanf("%s", Dustin->firstName);
	printf("\nINPUT LAST NAME\n");
	scanf("%s", Dustin->lastName);
	printf("\nINPUT ID\n");
	scanf("%d", &Dustin->personID);

	printf("First Name: %s , Last Name %s , ID: %d\n", Dustin->firstName, Dustin->lastName, Dustin->personID);


	free(Dustin);
}
