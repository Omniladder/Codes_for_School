#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

struct person{
    int id;
    char name[30];
};

int main()
{
    person* peopleArray = (struct person )calloc(12, person);
}