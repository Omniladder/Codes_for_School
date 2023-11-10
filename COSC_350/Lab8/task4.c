#include <signal.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int string_to_int(char*);

int main(int numInputs, char** commandLine)
{
	int fileDescriptor[2];

	pid_t child;
	pipe(fileDescriptor);
	
	child = fork();


	if(child == 0)
	{
		close(fileDescriptor[1]);
		char buff[999];
		int numBuff;
		int size = 0;
		int sum = 0;


		while(1)
		{
			size =read(fileDescriptor[0], buff, 999);
			printf("%s\n", buff);
			if(strcmp(buff,"EOF") == 0)
			{
				break;
			}
			else 
			{
				sum += string_to_int(buff);
			}
		}
		printf("sum is %d\n", sum);
		close(fileDescriptor[0]);
	}
	else
	{
		if(numInputs != 3)
		{
			printf("INPUT ONLY 2 Integers\n");
			kill(child, SIGTERM);
			exit(0);
		}	
		close(fileDescriptor[0]);

		write(fileDescriptor[1], commandLine[1], strlen(commandLine[0]));
		sleep(1);

		write(fileDescriptor[1], commandLine[2], strlen(commandLine[1]));
		sleep(1);

		write(fileDescriptor[1], "EOF", 3);
		close(fileDescriptor[1]);
	}
	int status;

	waitpid(child, &status, 0);
	return 0;
}

int string_to_int(char* string)
  {
          int result = 0;
			int i = 0;

			int neg = 1;

			if(string[0] == '-')
			{
				i++;
				neg = -1;
			}

          for(; string[i] != '\0'; i++)
          {
                  if(string[i] < '0' || string[i] > '9')
                  {
						printf("%s/n", string);
                        fprintf(stderr, "NON INTEGER INPUTTED\n");
						exit(-1);
                  }
                  else
                  result = result * 10 + string[i] - '0';
  
          }
  
          return result * neg;
  }
