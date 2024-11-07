#include "stdio.h"
#include "mpi.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

/*
Sum of Maximums
*/

double f(double x)
{
    return x * x;
}

int main(int argc, char** argv){
    if(argc <= 3)
    {
        printf("Inproper Number of Variables passed\n");
    }

    MPI_Init(&argc, &argv);

    int numComm = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &numComm);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int n = atoi(argv[3]);
    
    double startTime = MPI_Wtime();
    double sum = 0;

    double deltaX = (b - a * 1.0) / n;

    for(int i = 1; i <= n-1; i++)
    {
        sum += f(a + i * deltaX);
    }


    double Tn = deltaX * ((f(b) - f(a)) / 2 + sum);

    if(rank == 0)
    {
        double compTime = MPI_Wtime() - startTime;
        printf("Approximation: %fe%d\n", (Tn /pow(10,(int)log10(abs(Tn)))), (int)(log10(abs(Tn))));
        printf("Computation Time: %f\n", compTime);
    }

    MPI_Finalize();

}