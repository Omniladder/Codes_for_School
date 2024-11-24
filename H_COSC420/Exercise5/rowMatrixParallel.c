#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char** argv)
{
    
    if(argc < 2){
        printf("Invalid Number of Arguments\n");
        return -1;
    }
    //Initializes the arrays size
    int n = atoi(argv[1]);
    //Seeds Random
    srand(time(NULL));
    
    double startTime = omp_get_wtime();
    /**
     * This segment of code generates a n*n array of random doubles
     */
    double** AMatrix = (double**)malloc(sizeof(double*) * n);

    for(int row = 0; row < n; row++){
        AMatrix[row] = (double*)malloc(sizeof(double) * n);
        for(int col = 0; col < n; col++)
        {
            AMatrix[row][col] = (double)rand() / RAND_MAX;
        }
    }


    /**
     * This segment of code intializes the vector
     */
    double* xVector = (double*)malloc(sizeof(double) * n);
    double* bVector = (double*)malloc(sizeof(double) * n);

    for(int i = 0; i < n; i++){
        xVector[i] = (double)rand() / RAND_MAX;
    }


    /**
     *  This is the segment realted to matrix multiplcation
     */
    double product = 0;

    #pragma omp parallel for
    for(int row = 0; row < n; row++){
        double temp = 0;
        for(int col = 0; col < n; col++){
            temp += AMatrix[row][col] * xVector[col];
        }
        bVector[row] = temp;
    }
    

    /**
     * Outputs the newly calcualted vector
     */
    
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%.4f, ", bVector[i]);
    }
    printf("]\n");
    

    printf("The Program took %.4f Seconds\n", omp_get_wtime() - startTime);

    /**
     * Frees Matrixes and vectors
     */

    free(bVector);
    free(xVector);

    for(int row  = 0 ; row < n; row++){
        free(AMatrix[row]);
    }
    free(AMatrix);


    return 0;
}