#include <stdio.h>
#include <omp.h>

int main(){
    int arr[9];

    #pragma omp parallel for schedule(static) shared(arr)
    for(int i = 0; i < 9; i++)
    {arr[i] = i +1;}

    #pragma omp parallel for firstprivate(arr)
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < 9; j++){
            arr[j] *= i;
        }
        
        printf("first 5 multiples of %d\n", i);
        printf("[%d, %d, %d, %d, %d, %d, %d, %d, %d]\n\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);

        for(int j = 0; j < 9; j++){
            arr[j] /= i; //Undoes previous change
        }
    }
}