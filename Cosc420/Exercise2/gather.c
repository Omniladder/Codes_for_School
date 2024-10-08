#include "stdio.h"
#include "mpi.h"
#include <stdlib.h>
#include <string.h>

/*
Modified version of the Summation program using gather in order to collect all the sums
*/

int main(int argc, char** argv){
    //printf("Hello World\n");

       //Input Validation
    if(argc < 2)
    {
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    if(!atoi(argv[1]) && argv[1][0] != '0')
    {
        printf("Invalid Parameter\n");
        return -1;
    }

    MPI_Init(&argc, &argv);

    int numComm = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &numComm);

    int sum = 0;

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);



    int start = 1;
    int end = atoi(argv[1]);

    int segStart = rank * end / numComm + 1;
    int segEnd = (rank + 1) * end / numComm;

    for(int i = segStart; i <= segEnd; i++)
    {
        sum += i;
    }

    MPI_Status status;

    int sums[numComm];

    MPI_Gather(&sum, 1, MPI_INT, sums, 1, MPI_INT, 0, MPI_COMM_WORLD);


    if(rank == 0)
    {
        int finalSum = 0;
        for (int i = 0; i < numComm; i++)
        {
            finalSum += sums[i];
        }
        printf("Summation = %d\n", finalSum);
    }
      

    
    MPI_Finalize();
}