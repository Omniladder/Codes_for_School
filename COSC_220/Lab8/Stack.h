 #ifndef STACK_H
 #define STACK_H

 #include <iostream>
 #include <cstdlib>
 #include "ListCollection.h"

 using namespace std;

 template<class T>
 class Stack {
 private:
 ListCollection<T> stack;

 public:

 Stack();//
 ~Stack();//
 void displayStack(bool nl = true) ;//

 Stack(const Stack &obj);//
  Stack operator=(const Stack &right);//

 void clear();//
 int size() const;//
 void push(T);//
 T pop();
 bool isEmpty();//
 };

template<class T>
Stack<T>::Stack()
{
  //cout<<"Constructor"<<endl;
}

template<class T>
Stack<T>::~Stack()
{
  //cout<<"Deconstructor Called"<<endl;
  //delete stack;
}

template<class T>
void Stack<T>::displayStack(bool nl)
{
  //cout<<"Displayed Called"<<endl;
  if(nl)
  {
    //cout<<size();
    for(int i=0;i<size();i++)
      {
        //cout<<size;
        //cout<<"trigered"<<endl;
        cout<<stack.getElement(i)<<" ";
      }
  }
}

template<class T>
 Stack<T> Stack<T>::operator=(const Stack &right)
{
  clear();
  stack=right.stack;
  return *this;
}

template<class T>
Stack<T>::Stack (const Stack &obj)
{
  clear();
  stack=obj.stack;
}

template<class T>
void Stack<T>::clear()
{
  //cout<<"clear Called"<<endl;
  stack.clear();
}

template<class T>
int Stack<T>::size()const
{
  //cout<<"size Called"<<endl;
  return stack.size();
}

template<class T>
bool Stack<T>::isEmpty()
{
  //cout<<"isEmpty Called"<<endl;
  if(size()==0)
  {return true;}
  else
  {return false;}
}

template<class T>
void Stack<T>::push(T val)
{
  //cout<<"push Called"<<endl;
  stack.pushFront(val);

}

template<class T>
T Stack<T>::pop()
{
  T temp;
  temp=stack.popFront();
  return temp;
}

 #endif
