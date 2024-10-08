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

    int nums[10];
       //Input Validation
       sleep(rank);
       srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        nums[i] = rand() % 10;
    }

    int max = 0;
    for(int i = 0; i < 10; i++)
    {
        if(max < nums[i])
        {
            max = nums[i];
        }
    }


    int maxSum;
    MPI_Allreduce(&max, &maxSum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);


    printf("Sum of Random Maximums is %d with Multiple of %d is %d\n", maxSum, rank, maxSum * rank);
    
      

    
    MPI_Finalize();
}