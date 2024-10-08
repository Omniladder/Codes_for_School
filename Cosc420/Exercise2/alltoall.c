#include "stdio.h"
#include "mpi.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
Modified version of the Summation program using gather in order to collect all the sums
*/

int main(int argc, char** argv){


    MPI_Init(&argc, &argv);

    int numComm = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &numComm);

    int sum = 0;

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    //Matrix Transposisition
    int size = 10;

    int row[numComm];


    sleep(rank);
    srand(time(0));
    printf("Rank %d: ", rank);
    printf("[");
    for(int i = 0; i < numComm; i++)
    {
        row[i] = rand() % 10 + 1;
        printf("%d, ", row[i]);
    }
    printf("]\n");

    int newRow[numComm];
    MPI_Alltoall(row, 1, MPI_INT, newRow, 1, MPI_INT, MPI_COMM_WORLD);
    
    sleep(rank);
    if(rank == 0)
    printf("Transposed Version:\n");

    printf("[");
    for(int i = 0; i < numComm; i++)
    {
        printf("%d, ", newRow[i]);
    }
    printf("]\n");

    
    MPI_Finalize();
}