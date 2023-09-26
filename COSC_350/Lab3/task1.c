#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
int inFile, outFile;
char Ach;

/* open file for read only */
inFile = open("foo", O_RDONLY);

/* open file for write only or create only, created file mode will rw_ _ _ _ _ _ _*/
outFile = open ("clone", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

while (read(inFile, &Ach, 1) == 1)
{
write(outFile, &Ach, 1);
}

close (InFileDes);
close (OutFileDes);

}