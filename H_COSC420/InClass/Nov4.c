
#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_num_threads(4);


    printf("\nStatic:\n");

    #pragma omp parallel for schedule(static, 1)
    for(int i = 0; i < 10; i++)
    {
       printf("Thread %d p(%d)\n", omp_get_thread_num(), i);
    }

    printf("\nDynamic:\n");
    #pragma omp parallel for schedule(dynamic, 1)
    for(int i = 0; i < 10; i++)
    {
        printf("Thread %d p(%d)\n", omp_get_thread_num(), i);
    }

    printf("\nGuided:\n");

    #pragma omp parallel for schedule(guided, 1)
    for(int i = 0; i < 10; i++)
    {
        printf("Thread %d p(%d)\n", omp_get_thread_num(), i);
    }

    printf("\nOrdered:\n");

    #pragma omp parallel for ordered
    for(int i = 0; i < 10; i++)
    {
        #pragma omp ordered
        {
            printf("Thread %d p(%d)\n", omp_get_thread_num(), i);
        }
    }

    printf("\n");
    
    
}