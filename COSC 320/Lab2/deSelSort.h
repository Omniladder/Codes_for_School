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

void swap(int& value1,int&  value2)
{
    int temporary= value1;
    value1 = value2;
    value2 = temporary;
    
}


 void deSelSort (int array[] , int size)
{
    //cout<<"test 3"<<endl;
    int Minimum_Array_Location = 0;
    int Maximum_Array_Location = 0;
    
    for (int i=0; i<size/2;i++)
    {
        //print_Array(array,size);
     Minimum_Array_Location = i;
     Maximum_Array_Location = i;
        for (int j=i+1; j<size-i;j++)
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

        swap(array[i],array[Minimum_Array_Location]);
        //cout<<"Swapping Index "<<i<<" and " <<Minimum_Array_Location<<endl;
        if(Maximum_Array_Location==i)
        {
            swap(array[size-i-1],array[Minimum_Array_Location]);
            //cout<<"Swapping Index "<<Minimum_Array_Location<<" and "<<Maximum_Array_Location<<endl;
        }
        else
        {
        swap(array[Maximum_Array_Location],array[size-i-1]);
        //cout<<"Swapping Index "<<size-i-1<<" and "<<Maximum_Array_Location<<endl;
        }
    }

    //print_Array(array,size);
}



#endif
