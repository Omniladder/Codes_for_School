#ifndef MINIARRAYSTACK_H
#define MINIARRAYSTACK_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;


template <class DataType>
 class miniArrayStack{
private:
enum {DEF_CAPACITY =100}; 	//default stack capacity
DataType* arr;	// The array of items
int	capacity;	// The size of the current array
int	top;	// The location of the top element
int stackSize;


 public:
 miniArrayStack (int cap= DEF_CAPACITY);	// Constructor for ArrStack //
miniArrayStack(const miniArrayStack<DataType> &); 	// Copy contstructor
~miniArrayStack();	// Destructor //
int  size()  const;	// get the number of elements in the stack //
 bool isEmpty() const;	// Check if the stack is empty //
const DataType& getTop() const; //throw(StackEmpty);       //get the top emement without popping it //
void push(const DataType&); //throw(StackFull);	// Pushes  an  object  onto  the  stack //
void pop() ;//throw(StackEmpty);	// Pop an object off the stack //
 void  printStack()  const;	// Prints the stack from the top, down //
miniArrayStack<DataType>& operator=(const  miniArrayStack<DataType>&);  //  Assignment  operator
};

//implementations go below...
template <class DataType>
miniArrayStack<DataType>::miniArrayStack(int cap)
{
  capacity=cap;
  arr = new DataType [cap];
  top = (arr[0]);
  stackSize=0;
}

template <class DataType>
miniArrayStack<DataType>::~miniArrayStack()
{delete[] arr;}

template <class DataType>
int miniArrayStack<DataType>::size() const
{return stackSize;}

template <class DataType>
bool miniArrayStack<DataType>::isEmpty() const
{
  if(stackSize==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class DataType>
const DataType& miniArrayStack<DataType>::getTop() const
{return arr[stackSize-1];}

template <class DataType>
void miniArrayStack<DataType>::push(const DataType& e)
{
  arr[stackSize]=e;
  stackSize++;
}

template <class DataType>
void miniArrayStack<DataType>::pop()
{
  arr[stackSize-1]=0;
  stackSize--;
}

template <class DataType>
void miniArrayStack<DataType>::printStack() const
{
  for(int i =stackSize-1; i>=0;i--)
    {

      cout<<arr[i]<<" ";
    }
  cout<<endl;
}

template <class DataType>
miniArrayStack<DataType>& miniArrayStack<DataType>:: operator=(const miniArrayStack<DataType>&e)
{
  for(int i = 0; i<e.size();i++)
    {
      arr[i]=e.arr[i];
    }
  return *this;
}




#endif
