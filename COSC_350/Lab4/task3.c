
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int palin(int File1, int File2);
int checkPalin(int File, int Start, int End);

int main(int num_Para, char** Input )
{
    if(num_Para > 2)
    {
        printf("PLEASE ENTER A FILE FOR INPUT\n");
        exit(-1);
    }
    if(num_Para < 2)
    {
        printf("ENTER IN ONE FILE\n");
        exit(-1);
    }

    int File1 = open(Input[1], O_RDONLY);
    if(File1 == -1)
    {
        printf("FILE FAILED TO OPEN\n");
        exit(-1);
    }

    int File2 = dup(File1);
    if(File2 == -1)
    {
        printf("FILE DUPLICATION FAILED\n");
    }




    if(palin(File1, File2) == 1)
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
    int answer = 1;
    char buff[1];
    char buff2[1];



    for(int i = 0; i <  (finish - start) / 2 ; i++)
    {
    pread(File, buff, 1, start + i);
    pread(File, buff2, 1, finish - i -1);
        if(buff[0] != buff2[0])
        {
            return 0;
        }
    }
    return 1;
}


int palin(int File1, int File2)
{
    char buff[1];
    int Displace1 = 0, Displace2 = 0; //Stores Location of Start and End of Word
    int count = 0;

    while(read(File1, &buff, 1) > 0)
    {
        if(buff[0] == ' ')
        {
            Displace2 = count;
            if( checkPalin(File2, Displace1, Displace2))
            {
                return 1;
            }
            Displace1 = count+1; 
            
        }
        count++;
    }
    count -= 1;
    Displace2 = count;
    if( checkPalin(File2, Displace1, Displace2))
      {  
        return 1;
      }
    return 0;

}