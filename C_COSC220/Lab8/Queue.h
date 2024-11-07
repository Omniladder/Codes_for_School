 #ifndef QUEUE_H
 #define QUEUE_H

 #include <iostream>
 #include <cstdlib>
  #include "ListCollection.h"

 using namespace std;

 template<class T>
 class Queue {
 private:
 ListCollection<T> queue;

 public:
 Queue();//
  ~Queue();//
 void displayQueue(bool nl = false) ;//

 Queue(const Queue &obj);
 const Queue operator=(const Queue &right);//

void clear();//
int size() const;//
void enqueue(T);//
 T dequeue();//
 bool isEmpty();//
 };
//template<class T>
/*Queue::Queue()
{}*/
template<class T>
Queue<T>::Queue()
{}

template<class T>
Queue<T>::~Queue()
{
  //delete[] queue;
}

template<class T>
void Queue<T>::clear()
{
  queue.clear();
}

template<class T>
void Queue<T>::displayQueue(bool nl)
{
  if(!nl)
  {
    //cout<<queue.size();
    for(int i=0;i<queue.size();i++)
      {

        //cout<<"triggered";
        cout<<queue.getElement(i)<<" ";
      }
    cout<<endl;
  }
}

template<class T>
int Queue<T>::size() const
{
  return queue.size();
}

template<class T>
bool Queue<T>::isEmpty()
{
  if(size()==0)
  {return true;}
  else
  {return false;}
}

template<class T>
T Queue<T>::dequeue()
{
  T temp = queue.popFront();
  return temp;
}

template<class T>
void Queue<T>::enqueue(T val)
{
  queue.pushBack(val);
}

template<class T>
const Queue<T> Queue<T>::operator=(const Queue &right)
{
  queue=right.queue;
  return *this;
}

template<class T>
Queue<T>::Queue (const Queue &obj)
{
  queue=obj.queue;
}

#endif
