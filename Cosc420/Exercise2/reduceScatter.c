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


    srand(time(0) + rank);
    /*printf("Rank %d: ", rank);
    printf("[");*/
    for(int i = 0; i < numComm; i++)
    {
        row[i] = rand() % 10 + 1;
        //printf("%d, ", row[i]);
    }
    //printf("]\n");

    int recvCounts[numComm];
    for(int i = 0; i < numComm; i++)
    {
        recvCounts[i] = 1;
    }

    int newSum;
    MPI_Reduce_scatter(row, &newSum, recvCounts, MPI_INT, MPI_SUM, MPI_COMM_WORLD);


    printf("Receive Data: Sums: %d Average: %f\n", newSum, newSum / (numComm * 1.0));    
    

    
    MPI_Finalize();
}