#include "deSelSort.h"
#include "binSearch.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int ArrSize = 10000;
    int RandomLimit = 99999;
    int RandomValues = 10000;
    srand(time(NULL));

    int array[ArrSize];
    for(int i=0;i<ArrSize;i++)
    {
        array[i]=(int) rand()%(RandomLimit+1);
    }
    deSelSort(array,ArrSize);
    //print_Array(array,ArrSize);
    bool success = false;
    int sumFailCom=0;
    int sumSucCom = 0;
    int successTotal = 0;
    int numofSearches = 0;
    int target = rand()%(RandomLimit+1);


     //numofSearches = binSearch(target,array,ArrSize,success);


    
    for(int i = 0; i<=RandomValues;i++)
        {
            target = (int) rand()%(RandomLimit+1);
            numofSearches = binSearch(target,array,ArrSize,success);
            if(success)
            {
                successTotal++;
                sumSucCom+=numofSearches;
            }
            else
            {
                sumFailCom+=numofSearches;
            }
        }

        cout<<"Worse case for failed attempts "<< sumFailCom/( RandomValues-successTotal)<<endl;
        cout<<"Worst case for successful attempts "<<sumSucCom/successTotal<<endl;
        
    return 0;

}
