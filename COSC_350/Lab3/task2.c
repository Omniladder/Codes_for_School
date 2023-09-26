#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
int inFile, outFile;
char temp;

char inFileName[256] = "";
char outFileName[256] = "";

printf("Enter in the file you plan on reading in \n");
scanf("%s" , inFileName);


/* open file for read only */
inFile = open(inFileName, O_RDONLY);

printf("Enter in the file you plan on copying to \n");
scanf("%s" , outFileName);

/* open file for write only or create only, created file mode will rw_ _ _ _ _ _ _*/
outFile = open (outFileName, O_WRONLY|O_CREAT, 0666);

while (read(inFile, &temp, 1) == 1)
{
write(outFile, &temp, 1);
}

close (inFile);
close (outFile);
 return 0;
}