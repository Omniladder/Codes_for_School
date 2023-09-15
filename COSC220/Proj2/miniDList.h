#ifndef MINIDLIST_H
#define MINIDLIST_H
#include <iostream>     // For cout
using namespace std;


template <class DataType>
class miniDList{
private:
struct   DNode{	// doubly linked list node
  DataType   data;	//  data stored in node
  DNode*   next;	//  next node in list
  DNode*   prev;	//  previous node  in list
};

 DNode* header;	// list sentinels
 DNode* trailer;
public:
miniDList(){                      // constructor
header = new DNode;
trailer  = new DNode;         //have them point to each other
header->next = trailer;
header->data = NULL;
trailer->data = NULL;
trailer->prev = header;
}
miniDList(const   miniDList<DataType>&  l);  // Copy constructor //
~miniDList();	// Destructor //
const DataType& front() const;      // get front element//
const DataType& back() const;       // get back element//
void   removeFront();	// Remove the front //
void   removeBack();             // Remove the back //
void addFront(const DataType& e);       // Add to the front //
void addBack(const DataType& e);           // Add to the back//
int   size()   const;	// Returns the number of elements in list //
bool contains(const DataType& e);   // Tests for membership //
void  display()  const;	// Prints the elements of list //
 miniDList<DataType>& operator=(const miniDList<DataType>& l);   //Overloaded assignment//

protected:                          //local utilities
void add(DNode * v, const DataType& e); //insert new node  before  v //
void remove(DNode* v);     //remove node v //
};

//implementations go below...

template <class DataType>
const DataType& miniDList<DataType>::front() const
{return header->data;}

template <class DataType>
const DataType& miniDList<DataType>::back() const
{return trailer->data;}

template <class DataType>
void miniDList<DataType>::removeFront()
{
  DNode* temp = new DNode;
  temp = header;
  if(size()>1)
  {
    header=header->next;
    delete temp;
    return;
  }
  if(size()<=1)
  {
    delete temp;
    header->next=trailer;
    return;
  }
}

template <class DataType>
void miniDList<DataType>::removeBack()
{
  //cout<<trailer->data<<" trailer data ";
  DNode* temp = new DNode;
  temp = trailer;
  if(size()>2)
  {
   trailer=trailer->prev;
    delete temp;
    return;
  }
  if(size()==2)
  {
    trailer->data=NULL;
    return;
  }
  if(size()==1)
  {
    delete temp;
    trailer->prev=header;
    return;
  }
}

template <class DataType>
void miniDList<DataType>::addFront(const DataType& e)
{

  if(header->data==NULL) {
    header->data=e;
    header->next=trailer;
    return;
  }
  if(trailer->data==NULL) {
    trailer->data= header->data;
    header->data = e;
    header->next=trailer;
    return;
  }

  DNode* temp = new DNode;
  temp->data=e;
  temp->next=header;
  temp->prev=nullptr;

  header->prev=temp;
  header=temp;


}

template <class DataType>
void miniDList<DataType>::addBack(const DataType& e)
{
  if(trailer->data==NULL) {
    trailer->data=e;
    trailer->prev=header;
    return;
  }
  if(header->data==NULL) {
    header->data= trailer->data;
    trailer->data = e;
    trailer->prev=header;
    return;
  }

  DNode* temp = new DNode;
  temp->data=e;
  temp->prev=trailer;
  temp->next=nullptr;

  trailer->next=temp;
  trailer=temp;
}

template <class DataType>
int miniDList<DataType>::size() const
{
  int counter = 0;
  DNode* node = header;
  //cout<<header->data<<" data "<<endl;
  //header->data;
  while((node->data != NULL) && (header->data != NULL) && (node->next != nullptr))
    {
      //cout<<node<<" "<<counter<<" ";
      //cout<<node->next<<" next ";
      counter++;
      node =node->next;
    }
  if(counter!=0)
  {counter++;}

  return counter;
}

template <class DataType>
bool miniDList<DataType>::contains(const DataType& e)
{
  DNode* node = header;
  while(node->next&&header->data&&trailer->data)
    {
      if(node->data==e)
      {
        return true;
      }
    }
  return false;
}

template <class DataType>
void miniDList<DataType>::display() const
{
  DNode* node = header;
  //cout<<size()<<endl;
  for(int i = 0; i<size();i++)
    {
      cout<<node->data<<" ";
      node = node->next;
    }
  cout<<endl;
}

template <class DataType>
miniDList<DataType> &miniDList<DataType>:: operator=(const miniDList<DataType>& l)
{
  for(int i=0;i<this->size();i++)
    {this->removeBack();}
  DNode* node = l.header;
  for(int i=0;i<l.size();i++)
    {
      addFront(node->data);
      node = node->next;
    }
  return *this;
}

template <class DataType>
miniDList<DataType>:: miniDList(const   miniDList<DataType>&  l)
{
  for(int i=0;i<this->size();i++)
    {this->removeBack();}
  DNode* node = l.header;
  for(int i=0;i<l->size();i++)
    {
      addFront(node->data);
      node = node->next;
    }
}

template <class DataType>
miniDList<DataType>:: ~miniDList()
{
  for(int i=0;i<this->size();i++)
    {this->removeBack();}
}

template <class DataType>
void miniDList<DataType>:: add(DNode * v, const DataType& e)
{
  DNode* node = header;
  while(node->next&&!(node->data==v->data&&node->next==v->next&&node->prev==v->prev))
    {
      node = node->next;
    }
  DNode* temp;
  temp->data = e;
  temp->next = node;
  temp->prev = node->prev;
  node->prev = temp;
  temp->prev->next=temp;
}


template <class DataType>
void miniDList<DataType>:: remove(DNode * v)
{
  DNode* node = header;
  while(node->next&&!(node->data==v->data&&node->next==v->next&&node->prev==v->prev))
    {
      node = node->next;
    }
    if(node->next&&node->prev)
    {
      node->prev->next=node->next;
      node->next->prev=node->prev;
      return;
    }
    if(!node->next&&node->prev)
    {
      node->prev->next=nullptr;
    }
  if(node->next&&!node->prev)
    {
      node->next->prev=nullptr;
    }

}


#endif
