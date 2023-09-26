#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

char buffer[128];
int nread;


while ((nread = read(0, buffer, 128)) != -1)
{

nread = read(0, buffer, 128);


}


return 0;
}
