#include <stdio.h>
#include <omp.h>

/**
 * Generates a Times Table ordered required in order to make sure print in correct order
 */

int main() {
    int arr[13][13];  

    
    #pragma omp parallel for collapse(2) ordered
    for (int i = 0; i <= 12; i++) {
        for (int j = 0; j <= 12; j++) {
            arr[i][j] = i * j;

            #pragma omp ordered //Keeps Multipcation table in ordr
            if (j == 12) { //Prints only at end
                printf("[ ");
                for (int k = 0; k <= 12; k++) {
                    printf("%d, ", arr[i][k]);
                }
                printf("]\n");
            }
        }
    }

    return 0;
}