#include "stdio.h"
#include "mpi.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
Sum of Maximums
*/



int main(int argc, char** argv){
    //printf("Hello World\n");

    MPI_Init(&argc, &argv);

    int numComm = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &numComm);

    int sum = 0;

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int currentSum = 0;

    MPI_Scan(&rank, &currentSum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("The %dth elements of the sum is %d\n", rank, currentSum);
      

    
    MPI_Finalize();
}