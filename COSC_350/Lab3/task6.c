#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
int inFile, outFile; //holds File ID's for reading and writing too
char temp; //stores one charcter for transfer

char inFileName[256] = ""; // holds the file being read name
char outFileName[256] = ""; // holds the file being copied too name


printf("Enter in the file you plan on reading in \n"); //prompts user
scanf("%s" , inFileName); // reads in the file name given by user


inFile = open(inFileName, O_RDONLY); //Opens the read file 

printf("Enter in the file you plan on copying to \n"); // prompts user
scanf("%s" , outFileName); // reads in the file that data should be sent too


outFile = open (outFileName, O_WRONLY|O_CREAT, 0760); //opens file used for outputting

int displace = 0;

while(read(inFile, &temp, 1) > 0)
{
displace++;
}

displace -= 2;   

while(displace > 0)
{
pread(inFile, &temp, 1, displace);
write(outFile, &temp, 1);
displace--;
}

close (inFile);
close (outFile); //closes file
 return 0;
}