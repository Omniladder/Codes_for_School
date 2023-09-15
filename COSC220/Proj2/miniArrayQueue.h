#ifndef MINIARRAYQUEUE_H
#define MINIARRAYQUEUE_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
 class miniArrayQueue {
    private:
DataType* arr;		// The array of items
int	capacity;	// The size of the current array
int	front;	// The location of the front element
int	rear;	// The location of the rear element
int queueSize;

 public:
miniArrayQueue ();	// Constructor //
miniArrayQueue(const miniArrayQueue<DataType> &); // Copy Constructor //
~miniArrayQueue();	//   Destructor //
int   size()   const;	// get the number of elements in the queue //
bool isEmpty() const;	// Check if the queue is empty //
void  enqueue(const  DataType& e); //throw(QueueFull), Enqueue element at rear //
void  dequeue();     //throw(QueueEmpty), dequeue element at front //
const DataType& getFront() const ;//throw(QueueEmpty), return the front element but not remove //
DataType returnIndex(int i) const;
void  printQueue()  const;	// Prints the queue from the front to the rear //
 miniArrayQueue<DataType>& operator=(const miniArrayQueue<DataType>&); // Assignment operator //
};


//implementations go below...

template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue()
{
  capacity = 100;
  arr = new DataType[capacity];
  queueSize = 0;
  front = (arr[0]);
  rear = (arr[queueSize]);
}

template <class DataType>
miniArrayQueue<DataType>::~miniArrayQueue()
{
  delete[] arr;
}

template <class DataType>
int miniArrayQueue<DataType>::size() const
{return queueSize;}

template <class DataType>
bool miniArrayQueue<DataType>::isEmpty() const
{if(queueSize==0){return true;}
  else{return false;}}

template <class DataType>
void miniArrayQueue<DataType>::enqueue(const  DataType& e)
{
  arr[queueSize]=e;
  queueSize++;
}

template <class DataType>
void miniArrayQueue<DataType>::dequeue()
{
    if (isEmpty())
        throw(QueueEmpty("error"));
    
    arr[queueSize-1]=0;
    queueSize--;
}

template <class DataType>
const DataType& miniArrayQueue<DataType>::getFront() const
{return arr[0];}

template <class DataType>
void miniArrayQueue<DataType>::printQueue() const
{
  for(int i =0; i<queueSize;i++)
    {
      cout<<arr[i]<<" ";
    }
  cout<<endl;
}

template <class DataType>
miniArrayQueue<DataType>& miniArrayQueue<DataType>:: operator=(const miniArrayQueue<DataType>&e)
{

  arr = new DataType[100];
  capacity = e.capacity;
  queueSize=e.queueSize;
  front = arr[0];
  rear = arr[queueSize];

  for(int i = 0; i<e.size();i++)
    {
      arr[i]=e.arr[i];
    }
  return *this;
}



template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(const miniArrayQueue<DataType> &e)
{
  arr = new DataType[100];
  capacity = e.capacity;
  queueSize=e.queueSize;
  front = arr[0];
  rear = arr[queueSize];

  for(int i = 0; i<e.size();i++)
    {
      *(arr+i)=e.arr[i];
    }
}


#endif
