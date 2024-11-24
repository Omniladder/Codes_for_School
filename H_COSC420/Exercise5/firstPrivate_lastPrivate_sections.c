#include <stdio.h>
#include <math.h>


/**
 * Average of Summation
 */
int main()
{
    double num = 0;
    #pragma parallel firstprivate(num) lastprivate(num) sections
    {
        #pragma nowait section
        {
            for(int i =0; i <= 10; i++)
            {
                num += i;
            }
            num /= 10;
            printf("First 10 Sum Average: %f\n", num);
        }
        #pragma nowait section
        {
            for(int i =0; i <= 20; i++)
            {
                num += i;
            }
            num /= 20;
            printf("First 20 Sum Average: %f\n", num);
        }
        #pragma nowait section
        {
            for(int i =0; i <= 30; i++)
            {
                num += i;
            }
            num /= 30;
            printf("First 30 Sum Average: %f\n", num);
        }
    }
    
     printf("Final Averahe of Sums was %f:\n", num);

}