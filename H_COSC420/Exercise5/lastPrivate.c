#include <stdio.h>
#include <omp.h>

int main(){

    int lastThread = 0;
    int sum = 0;
    #pragma omp parallel for lastprivate(lastThread) private(sum)
        for(int i = 0; i < 10000; i++)
        {
            sum *= i;
            sum -= i;
            sum *= -1;
            lastThread = omp_get_thread_num();
        }
    

    printf("The Last Thread was %d\n", lastThread);
}