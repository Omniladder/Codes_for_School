#include "stdio.h"
#include "mpi.h"
#include <math.h>
#include <stdlib.h>
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
        return -1;
    }

     MPI_Init(&argc, &argv);

    int numComm = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &numComm);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double startTime = MPI_Wtime();

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double n = atof(argv[3]);
    
    double segSum = 0;
    double sum = 0;

    double deltaX = (b - a) / n;


    int segStart = rank * (n / numComm);
    int segEnd = (rank + 1) * (n / numComm);

    for(int i = segStart; i < segEnd; i++)
    {
        segSum += f(a + i * deltaX);
    }

    MPI_Reduce(&segSum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    double compTime = MPI_Wtime() - startTime;

    double Tn = deltaX * ((f(b) + f(a)) / 2 + sum);

    Tn -= deltaX * f(a); //Remoces f(a) from sum


    double timeMin, timeMax, timeAvg;

    MPI_Reduce(&compTime, &timeMin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&compTime, &timeMax, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&compTime, &timeAvg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0)
    {
        printf("Approximation: %fe%d\n", (Tn /pow(10,(int)log10(abs(Tn)))), (int)(log10(abs(Tn))) ); //Prints in scientific Notation
        printf("Minimum Comptuational Time: %fs\n", timeMin);
        printf("Maximum Comptuational Time: %fs\n", timeMax);
        printf("Average Comptuational Time: %fs\n", timeAvg / numComm);
    }


    MPI_Finalize();
}