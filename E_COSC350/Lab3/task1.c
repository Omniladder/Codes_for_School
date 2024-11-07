#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

char buffer; //Buffer used to store arrays to be sent to file


while (read(0, &buffer, 1) > 0) // reads in every charcter
{

write(1 , &buffer, 1); //writes charcter to file

}


return 0; //ends code
}
