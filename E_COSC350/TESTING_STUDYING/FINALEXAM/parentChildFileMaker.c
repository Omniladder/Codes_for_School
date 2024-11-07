#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int numCommands, char** commandLine)
{
	pid_t child;

	int inputFile, letterFile, numberPhile;

	if(numCommands != 4)
	{
		printf("ENTER 4 Files first is input file second is letter file and third is the number file\n");
		exit(-1);
	}

	if(access(commandLine[1], F_OK) == -1 && access(commandLine[1], R_OK) == -1)
	{
		printf("Input File Either Doesn't Exist or Isn't Readable\n");
		exit(-1);
	}

	inputFile = open(commandLine[1], O_RDONLY);
	
	letterFile = open(commandLine[2], O_WRONLY | O_CREAT, 0666);
	numberPhile = open(commandLine[3], O_WRONLY | O_CREAT, 0666);

	int sizeFile = lseek(inputFile, 0, SEEK_END);

	char buff[1];
	
	child = fork();
	if(child == 0) //ACTUAL CHILD
	{
		for(int i = 0; i < sizeFile; i++)
		{
				lseek(inputFile, i, SEEK_SET);
				read(inputFile, buff, 1);
	
				if((buff[0] - 'a' >= 0 && buff[0] - 'a' <= 25) || (buff[0] - 'A' >= 0 && buff[0] - 'A' <= 25)) //Remember second or to take capitals too
				{
					write(letterFile, buff, 1);
				}
				else
				{
					write(letterFile, " ", 1);
				}

		}
	}
	else
	{
		for(int i = 0; i < sizeFile; i++)
		{
			lseek(inputFile, i, SEEK_SET);
			read(inputFile, buff, 1);

			if(buff[0] - '0' >= 0 && buff[0] - '0' <= 9)
			{
				write(numberPhile, buff, 1);
			}
			else
			{
				write(numberPhile, " ", 1);
			}
		}
	}


	close(inputFile);
	close(letterFile);
	close(numberPhile); //REMEMBER TO  CLOSE

}
