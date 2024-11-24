#include <omp.h>
#include <stdio.h>
#include <math.h>


/**
 * calculates all the ptime numbers to the ending index
 */
int main()
{

    int endingIndex = 700;
    int primes[endingIndex];

    #pragma omp parallel for schedule(dynamic)
    for(int i = 0;  i < endingIndex; i++){
        primes[i] = i;
    }

    #pragma omp parallel
    {
        #pragma omp nowait single
        {
            for(int i = 2 ; i < (endingIndex); i++)
            {
                #pragma omp task firstprivate(i) shared(primes)
                {
                    for(int g = i + i; g < endingIndex; g += i){
                            primes[g] = -1;
                    }
                }
            }
            #pragma omp taskwait
        }
    }

    for(int i = 2; i < endingIndex; i++)
    {
        if(primes[i] != -1){
            printf("%d is prime\n", primes[i]);
        }
    }
}