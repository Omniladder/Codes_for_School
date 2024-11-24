#include <omp.h>
#include <stdio.h>

/**
 * Quadratic Polynomial Solver
 */

int main()
{
    double coefficients[] = {2.0,5.0,3.0}; // 2x^2 + 5x + 3
    double x = 3.2;
    double sum =0;
    
    #pragma omp parallel sections reduction(+:sum) 
    {
        #pragma omp nowait section 
        {
            sum += coefficients[0] * x * x;
        }

        #pragma omp nowait section 
        {
            sum += coefficients[1] * x;
        }

        #pragma omp nowait section
        {
            sum += coefficients[2];
        }
    }

    printf("The Answer to this quadratic is %.4f\n", sum);
}