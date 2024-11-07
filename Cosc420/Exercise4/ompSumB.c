#include "stdio.h"                                                                                                                                                                
#include "omp.h"
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

    int sum = 0;
    int end = atoi(argv[1]);

    double startTime = omp_get_wtime();

    #pragma omp parallel for
        for(int i = 0; i <= end; i++)
        {
            #pragma omp critical
            {
                sum += i;
            }
        }
        
    printf("Sum : %d :: Time: %f\n", sum, omp_get_wtime() -  startTime);
}
