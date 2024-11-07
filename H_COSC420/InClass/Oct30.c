#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv)
{

   int nthreads, tid;
    omp_set_num_threads(5);
    int a[1000];
    int b[1000];
    int c[1000];

    for(int index = 0; index < 1000; index++)
    {
        a[index] = index;
        b[index] = index;
    }

    int i =0;

    #pragma omp parallel
    {
        int count = 0;
        #pragma omp for
        for(i = 0; i < 1000; i++)
        {
            c[i] = a[i] + b[i];
            count++;
        }
        printf("Thread %d ran %d iterations\n", omp_get_thread_num(),count);
    }
    
}