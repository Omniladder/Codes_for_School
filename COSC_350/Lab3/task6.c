#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
int inFile, outFile; //holds File ID's for reading and writing too
char temp; //stores one charcter for transfer

umask(0000);

char inFileName[256] = ""; // holds the file being read name
char outFileName[256] = ""; // holds the file being copied too name


printf("Enter in the file you plan on reading in \n"); //prompts user
scanf("%s" , inFileName); // reads in the file name given by user


inFile = open(inFileName, O_RDONLY); //Opens the read file 

if (access(inFileName, F_OK) != 0)
{
        printf("FILE DOESNT EXIST");  
        exit (1);
}

if (access(inFileName, R_OK) != 0)              
{
        printf("FILE ISN'T READABLE");
        exit (1);
}



printf("Enter in the file you plan on copying to \n"); // prompts user
scanf("%s" , outFileName); // reads in the file that data should be sent too


outFile = open (outFileName, O_WRONLY|O_CREAT, 0760); //opens file used for outputting

int displace = 0;//stores distance to set cursor from front

while(read(inFile, &temp, 1) > 0) //used to store size of infile
{
displace++; //counts up size
}

displace -= 2;   //properly sets the displace

while(displace > 0) //runs while cursor still in file
{
pread(inFile, &temp, 1, displace); //reads in the char
write(outFile, &temp, 1);//writes that char down
displace--;//moves cursor back 1
}

close (inFile); //closes file
close (outFile); //closes file
 return 0;//ends program
}
