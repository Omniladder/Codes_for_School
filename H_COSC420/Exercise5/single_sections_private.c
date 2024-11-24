#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{

    int num;

    #pragma omp parallel sections private(num) 
    {
        #pragma single
        {
            printf("There are %d Threads on this task\n", omp_get_num_threads());
        }

        #pragma omp section
        {
            num = 1;
            for(int i = 1; i <= 10; i++)
            {
                num *= i;
                
            }
            printf("10! = %d\n", num);
        }

        #pragma omp section
        {
            num = 0;
            for(int i = 0; i < 10; i++)
            {
                num += i;
            }
            printf("summation up to 10 is %d\n", num);
        }
    }
}