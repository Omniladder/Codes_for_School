 #ifndef PRIORITYQUEUE_H
 #define PRIORITYQUEUE_H

 #include <iostream>
 #include <vector>

 /*
8 Description: Templated Priority Queue class that uses the STL vector as the underlying
storage structure.
9 Note: The template class T must
10 1. overloaded =
11 2. Have a default constructor
12 3. Overloaded >>
13 4. Copy Constructor
14 */

 using namespace std;

 // Node data type that holds the data and
 // priority of the item.

 template<class T>
 class PQNode {
 public:
 T data;
int priority;

 PQNode(T Data) {
 data = Data;
 priority = 1;
 }

 PQNode(T Data, int Priority) {
 data = Data;
 if (Priority < 1)
 Priority = 1;

 priority = Priority;
 }
 };

 template<class T>
 class PriorityQueue {
private:

 vector<PQNode<T> > queue; // The vector holding all of the items in the queue.

 public:
 // Constructors and Destructor
 PriorityQueue();//
 PriorityQueue(const PriorityQueue &obj);//
  ~PriorityQueue();//

 // Acessors and Mutators
 void enqueue(T Data, int Priority = 1);
 T dequeue();

 // Other Functions
 void print();//
 bool isEmpty();//
 void clear();//
  int size();
 };


template<class T>
int PriorityQueue<T>::size()
{
  return queue.size();
}

template<class T>
void PriorityQueue<T>::enqueue(T Data, int Priority)
{
  PQNode<T> nNode(Data);
  nNode.data = Data;
  nNode.priority = Priority;
  queue.insert(queue.end(),nNode);
}

template<class T>
T PriorityQueue<T>::dequeue()
{
  
  int index = 0;
  for(int i = 0; i<size();i++)
    {
      if(queue[index].priority<queue[i].priority)
      {
        index=i;
      }
    }
  
  T output = queue[index].data;
  queue.erase((queue.begin()+index));
  
  
  return output;
  
  //delete temp;
}



template<class T>
PriorityQueue<T>::PriorityQueue()
{}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{}

template<class T>
bool PriorityQueue<T>::isEmpty()
{
  if(queue.size()==0)
    {
    return true;
    }
  else
  {
    return false;
  }
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj)
{
  for(int i=obj.size()-1;i>0;i++)
    {
      pushBack(obj[i]);
    }
  //return *this;
}

template<class T>
void PriorityQueue<T>::print()
{
  
  for(int i=0;i<queue.size();i++)
    {
      cout<<queue[i].data<<" --- "<<queue[i].priority<<endl;;
    }
  
}

template<class T>
void PriorityQueue<T>::clear()
{
  queue.clear();
}


 #endif
  
