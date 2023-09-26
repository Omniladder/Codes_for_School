#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
int inFile, outFile; //holds File ID's for reading and writing too
char temp[32]; //stores one charcter for transfer

char inFileName[256] = ""; // holds the file being read name
char outFileName[256] = ""; // holds the file being copied too name


printf("Enter in the file you plan on reading in \n"); //prompts user
scanf("%s" , inFileName); // reads in the file name given by user


inFile = open(inFileName, O_RDONLY); //Opens the read file 

printf("Enter in the file you plan on copying to \n"); // prompts user
scanf("%s" , outFileName); // reads in the file that data should be sent too


outFile = open (outFileName, O_WRONLY|O_CREAT, 0770); //opens file used for outputting

while (read(inFile, &temp, 32) >= 1) // loops therought every charter in read file
{
write(outFile, &temp, 32); //send charcter tot thhe write file
}

printf("Enter in the file you plan on reading in \n"); //prompts user
scanf("%s" , inFileName); // reads in the file name given by user

lseek(outFileName, 0, SEEK_END);


while (read(inFile, &temp, 32) >= 1) // loops therought every charter in read file
{
write(outFile, &temp, 32); //send charcter tot thhe write file
}

close (inFile);
close (outFile); //closes file
 return 0;
}