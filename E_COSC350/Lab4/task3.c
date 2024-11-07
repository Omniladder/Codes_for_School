
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int palind(int File1, int File2);//used to check if theirs a palindrome in file
int checkPalin(int File, int Start, int End);//checks if individual word is a palindrome

int main(int num_Para, char** Input )
{
    if(num_Para > 2)//CHECKS FOR PROPER NUMBER OF INPUTS
    {
        printf("PLEASE ENTER A FILE FOR INPUT\n");
        exit(-1);
    }
    if(num_Para < 2)//CHECKS FOR PROPER NUMBER OF INPUTS
    {
        printf("ENTER IN ONE FILE\n");
        exit(-1);
    }

    int File1 = open(Input[1], O_RDONLY);//OPENS FILE FIRST TIME
    if(File1 != 0)//MAKES SURE FILE OPENED
    {
        perror("FILE FAILED TO OPEN\n");
        exit(-1);
    }

    int File2 = dup(File1);//DUPLICATES FILE DESCRIPTOR FOR SECOND ONE
    if(File2 == -1)//MAKES SURE DUPLICATION WORKED
    {
        perror("FILE DUPLICATION FAILED\n");
    	exit(1);
    }




    if(palind(File1, File2) == 1)//tests if file is paldrome or not and outputs coorespondingly
    {
        printf("File Contains Palinedrome\n");
    }
    else
    {
        printf("File Does't contain Pailendrome\n");
    }
    exit (0);
}

int checkPalin(int File, int start, int finish)
{
    char buff[1];//used to store left side bit
    char buff2[1];//used to store right side bit



    for(int i = 0; i <  (finish - start) / 2 ; i++)//loops through the word so both sides can read through it
    {
    pread(File, buff, 1, start + i);//reads in left side
    pread(File, buff2, 1, finish - i -1);//reads in right side
        if(buff[0] != buff2[0])//makes sure both sides are equal else its not a palindrome
        {
            return 0;//returns proper error
        }
    }
    return 1;//says their a palindrome
}


int palind(int File1, int File2)
{
    char buff[1];//USED TO STORE LETTERS TO FIND START AND END OF A WORD
    int Displace1 = 0, Displace2 = 0; //Stores Location of Start and End of Word STARTS AT 0 INCASE FIRST WORD IS PALINDROME
    int count = 0;//KEEPS TRACK OF LOCATION IN FILE

    while(read(File1, &buff, 1) > 0)//LOOPS THROUGH THE FILE
    {
        if(buff[0] == ' ')//CHECKS IF WE HIT END OF WORD
        {
            Displace2 = count;//SETS END TO CURRENT LOCATION
            if( checkPalin(File2, Displace1, Displace2))//CHECKS IF WORD IS A PALINDROME
            {
                return 1;//IF SO RETURNS TRUE
            }
            Displace1 = count+1; //SETS START OF WORD AT NEXT WORD
            
        }
        count++;//INCREMENTS TO KEEP TRACK OF LOCATION
    }
    Displace2 = count - 1;//SAVES DISPLACE TO TEST IF LAST WORD WHICH MAY NOT HAVE A SPACE IS A PALINDROME
    if( checkPalin(File2, Displace1, Displace2))//CHECKS IF LAST WORD IS A PALINDROME
      {  
        return 1;//Returns TRUE IF SO
      }
    return 0;//RETURNS FALSE IF NO WORDS ARE PALINDROMES

}
