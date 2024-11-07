#ifndef deSelSort_H
#define deSelSort_H

#include <iostream>

using namespace std;


void print_Array(int array[] , int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}


void deSelsort (int array[] , int size)
{

    int Minimum_Array_Location = 0;
    int Maximum_Array_Location = 0;
    int Temporary= 0;
    for (int i=0; i<(size/2)+.5;i++)
    {
        print_Array(array,size);
     Minimum_Array_Location = i;
     Maximum_Array_Location = i;
        for (int j=i; j<size-i;j++)
        {
            if(array[Maximum_Array_Location]<array[j])
            {
                Maximum_Array_Location=j;
            }

            if(array[Minimum_Array_Location]>array[j])
            {
                Minimum_Array_Location=j;
            }
        }

        Temporary = array[i];
        array[i]=array[Minimum_Array_Location];
        array[Minimum_Array_Location] = Temporary;

        Temporary = array[size-i-1];
        array[size-i-1]=array[Maximum_Array_Location];
        array[Maximum_Array_Location] = Temporary;

        
    }

    print_Array(array,size);
}



#endif
