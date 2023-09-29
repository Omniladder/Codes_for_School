#ifndef binSearch_H
#define binSearch_H

#include <iostream>

using namespace std;

int binSearch (int target, int array[],int size,bool& ifFound)
{
    //cout<<"Version 5"<<endl;
    int start = 0;
    int end = size-1;
    int mid = ((start+end)/2);
    int counter =0;

    //cout<<"target is "<<target<<endl;

    while((array[mid]!=target && start<=end) )
    {
        //cout<<"checking index "<<mid<<endl;
        counter++;
        if(array[mid]>target)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }

        mid = ((start+end)/2);
    }
    //cout<<"Stopped at index "<<mid<<endl;
    if(array[mid]==target)
    {
        ifFound = true;
    }
    else
    {
        ifFound = false;
    }
    return counter;
}




#endif
