
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int numOfFiles, char* Inputs[])
{
	if(numOfFiles != 6)//CHECKS FOR PROPER NUMBER OF INPUTS
	{
	printf("INPUT 6 FILES\n");
	//PROMPTS USER OF PROBLEM
	exit (-1);
	//EXITS PROGRAM
	}


	int inFile = open(Inputs[1], O_RDONLY);
	//OPENS IN FILE
	int charFile = open(Inputs[2], (O_CREAT | O_RDWR),0777);
	//OPEN FILE TO HOLD CHARS
	int numFile = open(Inputs[3], (O_CREAT | O_RDWR),0777);
	//OPENS FILE TO HOLD NUM
	int othFile = open(Inputs[4], (O_CREAT | O_RDWR),0777);
	//OPEN GILE TO HOLD OTHER CHARS
	int copy = open(Inputs[5],(O_CREAT | O_RDWR), 0777);
	//OPENS COPY FILE
	

	char buff[1];
	//USED TO STORE DATA FROM FILE
	char space[1];
	//USED TO HOLD A SPACE INORDER TO WRITE THE SPACES
	space[0] = ' ';
	//SETS SPACE TO A SPACE CHAR
	int num = 0; int size = 0;
	//used to store integer form of number and holds size of a file
	while(read(inFile, buff, 1) > 0) //READS IN WHOLE FILE
	{

	num = (int) buff[0];//SETS NUM TO ASCII CODE FOR CHAR



	if(num == 48 || num == 49 || num == 50 || num == 51 || num == 52 || num == 53 || num == 54 || num == 55 || num == 56 || num == 57) //CHECKS IF NUMBER
	{
	write(numFile, buff, 1);//puts in READ CHAR INTO NUM FILE
	}
	else
	write(numFile, space, 1);//SETS SLOT TO SPACE

	if(num == 65 || num == 66 || num == 67 || num == 68 || num == 69 || num == 70 || num == 71 || num == 72 || num == 73 || num == 74 || num == 75 || num == 76 || num == 77 || num == 78 || num == 79 || num == 80 || num == 81 || num == 82 || num == 83 || num == 84 || num == 85 || num == 86 || num == 87 || num == 88 || num == 89 || num == 90 || num == 97 || num == 98 || num == 99 || num == 100 || num == 101 || num == 102 || num == 103 || num == 104 || num == 105 || num == 106 || num == 107 || num == 108 || num == 109 || num == 110 || num == 111 || num == 112 || num == 113 || num == 114 || num == 115 || num == 116 || num == 117 || num == 118 || num == 119 || num == 120 || num == 121 || num == 122 ) //CHECKS IF LETTER
	{
	write(charFile, buff, 1);//PUTS LETTER IN CHAR FILE
	}
	else
	write(charFile, space, 1);//PUTS SPACE IN CHAR FILE

	if(num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 10 || num == 11 || num == 12 || num == 13 || num == 14 || num == 15 || num == 16 || num == 17 || num == 18 || num == 19 || num == 20 || num == 21 || num == 22 || num == 23 || num == 24 || num == 25 || num == 26 || num == 27 || num == 28 || num == 29 || num == 30 || num == 31 || num == 32 || num == 33 || num == 34 || num == 35 || num == 36 || num == 37 || num == 38 || num == 39 || num == 40 || num == 41 || num == 42 || num == 43 || num == 44 || num == 45 || num == 46 || num == 47 ||num == 58 || num == 59 || num == 60 || num == 61 || num == 62 || num == 63 || num == 64 ||num == 91 || num == 92 || num == 93 || num == 94 || num == 95 || num == 96 || num == 123 || num == 124 || num == 125 || num == 126 || num == 127) //WHAT IN TARNATION :: CHECKS IF NON LETTER OR NUMBER
	{
	write(othFile, buff, 1);//PUTS CHAR INTO THE OTHER FILE
	}
	else	
	write(othFile, space, 1);//PUTS SPACE INTO OTHER FILE
	
	size++;//KEEPS TRACK OF HOW MANY CHARS A FILE HAS
	}
	
close(othFile);//CLOSES FILE TO REOPEN IN READ STATE
close(charFile);//CLOSES CHAR FILE
close(numFile);//CLOSES NUM FILE
close(inFile);//CLOSES IN FILE


charFile = open(Inputs[2], O_RDONLY);//REOPENS CHAR FILE AS REad ONLY
numFile = open(Inputs[3], O_RDONLY);//REOPENS NUM FILE AS READ ONLY
othFile = open(Inputs[4], O_RDONLY);//REOPENS OTHER FILE AS READ ONLY

char buff2[1];//BUFFER FOR NUM FILE
char buff3[1];//VUFFER FOR OTHER FILE


for(int i = 0; i < size; i++)//LOOPS THROUGH ALL FILES FOR READING
{
read(charFile, buff, 1);
read(numFile, buff2, 1);
read(othFile, buff3, 1);//READS FROM ALL 3 FILES
	if(buff[0] != ' '){write(copy, buff, 1);}
	else if(buff2[0] != ' '){write(copy, buff2, 1);}
	else if(buff3[0] != ' '){write(copy, buff3, 1);}
	else {write(copy, space, 1);}//WRITES TO COPY WHICHEVER CHAR WAS IN ORIGINAL DETERMINED BY IF ITS A SPACE OR NOT
}	
	
	
	
	
	
	
	

}
