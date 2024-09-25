#include "stdio.h"                                                                                                                                                                
#include "mpi.h"
#include <stdlib.h>



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


    if(rank == 0)
    {
        int newSum = 0;
        for(int i = 1; i < numComm; i++)
        {
            MPI_Recv(&newSum, 1, MPI_INT, i, 10, MPI_COMM_WORLD, &status);
            sum += newSum;
        }

        printf("summation from 1 to %d: %d\n", end, sum);
    }
    else
    {
        MPI_Send(&sum, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
    }
        

    
    MPI_Finalize();
}