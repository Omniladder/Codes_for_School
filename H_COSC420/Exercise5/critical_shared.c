#include <stdio.h>
#include <omp.h>


/**
 * Parallelized Counting Program
 */
int main(){
    
    int count = 0;
    int count2 = 1000;

    #pragma omp parallel for shared(count, count2)
    {
        for(int i = 0; i < 10; i++)
        {
            #pragma omp critical //Allows for paralization of both counters while making sure values dont overwrite
            {
                count++;
            }
            #pragma omp critical
            {
                count2--;
            }
        }
    }
    #pragma omp barrier

    printf("I counted to %d\nand backwards to %d\n", count, count2);

}