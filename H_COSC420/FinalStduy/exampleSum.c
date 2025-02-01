#include <omp.h>
#include <stdio.h>

int main() {
    int i;

    // Parallel for loop with ordered region
    #pragma omp parallel for
    for (i = 0; i < 5; i++) {
        // Simulate some work
        printf("Thread %d before ordered block, i = %d\n", omp_get_thread_num(), i);

        #pragma omp ordered
        {
            // This block will execute in the same order as the loop iterations
            printf("Ordered block: i = %d, Thread: %d\n", i, omp_get_thread_num());
        }

        printf("Thread %d after ordered block, i = %d\n", omp_get_thread_num(), i);
    }

    return 0;
}
