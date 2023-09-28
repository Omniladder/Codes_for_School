#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

char buffer;
int nread;


while ((nread = read(0, &buffer, 1)) > 0)
{

write(1 , &buffer, 1);

}


return 0;
}
