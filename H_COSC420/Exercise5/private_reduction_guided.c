#include <stdio.h>
#include <omp.h>


int main()
{

    int sum = 0;

    #pragma omp parallel for schedule(guided) private(sum) reduction(+:sum) //Use Private to not cause a race condition between threads
    for(int i=0; i <= 1000; i++){
        sum+=i;
    }

    printf("Sum: %d\n", sum);
}