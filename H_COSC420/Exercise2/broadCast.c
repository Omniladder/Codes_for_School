#include "stdio.h"                                                                                                                                                                
#include "mpi.h"
#include <stdlib.h>
#include <string.h>

/*
    The idea of this program is that it allows the user to send and 
    run a bash command on every computer in a cluster at the same time
    without having to ssh into each or write a script to do so
*/

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("No command entered\n");
        return -1;
    }

    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Get the rank of the process
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); // Get the number of processes

    int stringSizes = 0;
    for (int i = 1; i < argc; i++)
    {
        stringSizes += strlen(argv[i]);
        stringSizes++; //One extra space for spaces
    }

        
    char commandString[stringSizes + 1];

    if(world_rank == 0)
    {

        int currentIndex = 0;

        for(int i = 1; i < argc; i++)
        {
            for(int j = 0; j < strlen(argv[i]); j++)
            {
                commandString[currentIndex] = argv[i][j];
                currentIndex++;
            }
            commandString[currentIndex] = ' ';
            currentIndex++;
        }
        commandString[stringSizes] = '\0';
    }

    MPI_Bcast(&commandString, stringSizes + 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (system(commandString) == -1)
    {
        printf("Command Failed\n");
    }
    
    MPI_Finalize();
    return 0;
}