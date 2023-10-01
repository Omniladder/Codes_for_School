#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
int inFile, outFile; //holds File ID's for reading and writing too
char temp; //stores one charcter for transfer

umask(0000); //default permissions

char inFileName[256] = ""; // holds the file being read name
char outFileName[256] = ""; // holds the file being copied too name


printf("Enter in the file you plan on reading in \n"); //prompts user
scanf("%s" , inFileName); // reads in the file name given by user


inFile = open(inFileName, O_RDONLY); //Opens the read file 

printf("Enter in the file you plan on copying to \n"); // prompts user
scanf("%s" , outFileName); // reads in the file that data should be sent too


outFile = open (outFileName, O_WRONLY|O_CREAT, 0760); //opens file used for outputting

int displace = -2; //stores the offset of too move the cursor

off_t fSize = lseek(inFile, displace, SEEK_END); //sets cursor at the end of the file and stores the offset

while ( (-1  * displace) - 3 < fSize) // loops therought every charter in read file and makes sure we havent passed offset
{
read(inFile, &temp, 1); //reads in the elements of the file given by displace
write(outFile, &temp, 1); //send charcter tot thhe write file
displace--;//assigns distance to move cursor back
lseek(inFile, displace, SEEK_END);//sets cursor back 1
}

close (inFile);//closes file
close (outFile); //closes file
 return 0;//ends program
}
