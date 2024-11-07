#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class ListCollection {
private:
struct ListNode {
		T value;           // The value in this node
		struct ListNode *next;  // To point to the next node
	};

	ListNode *head = new ListNode;            // List head pointer

	//T *list;
	
	//int numCapacity;
	bool isValid(int) const;
	void resize(int);

public:
	ListCollection();
	~ListCollection();//
	void setElement(int, T);
	T getElement(int) const;
	void displayList(bool nl = true) const;

	ListCollection( ListCollection &obj);
	const ListCollection<T> operator=(const ListCollection &right);

	const ListCollection<T> operator+(const ListCollection &right);
	const ListCollection<T> sublist(int, int);
	const ListCollection<T> sublist(int);
	const ListCollection<T> sort();

	void clear();
	int size();
	int capacity() const;
	void pushFront(T);
	void pushBack(T);
	T popFront();
	T popBack();
	void insertOrdred(T);
	void removeElement(T);
	void insert(int, T);
	void remove(int);

  //void appendNode(T);//
//void insertNode(T);//
//void deleteNode(T);//
//void deleteList();//
  
};

template<class T>
void ListCollection<T>::insertOrdred(T V)
{
  
  pushBack(V);
  *this = sort();
  //cout<<"List";
  //displayList();
}




template<class T>
void ListCollection<T>::removeElement(T num) {
	ListNode *nodePtr = new ListNode;       // To traverse the list
	ListNode *previousNode = new ListNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
    {return;}

	// Determine if the first node is the one.
	if (head->value == num) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
ListCollection<T>::~ListCollection() {
		ListNode *nodePtr = new ListNode;   // To traverse the list
	ListNode *nextNode = new ListNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
 //delete[] list;
}

template<class T>
void ListCollection<T>::clear() {
	ListNode *nodePtr = new ListNode;   // To traverse the list
	ListNode *nextNode = new ListNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	head = nullptr;
  //numCapacity=0;
}

template<class T>
int ListCollection<T>::size() {
	int count = 0;
	ListNode *nodePtr = new ListNode;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		count++;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return count;
  }








template<class T>
ListCollection<T>::ListCollection() {
  head= nullptr;
	//numCapacity = 0;
}



template<class T>
ListCollection<T>::ListCollection( ListCollection &obj) {
  //ListCollection nList;
  //cout<<"Start of copy"<<endl;
  //displayList();
  ListNode *read = obj.head;
	for (int i = 0; i < obj.size(); i++)
    {
      pushFront(read->value);
      read=read->next;
      
    }
  //displayList();
  //cout<<"End of copy"<<endl;
  //delete read;
  //numCapacity=obj.numCapacity;
  //return nList;
  //return this;
}

template<class T>
const ListCollection<T> ListCollection<T>::operator=(//warp
		const ListCollection &right) {
  //cout<<"Right"<<endl;
	//right.displayList();
  clear();
  
	ListNode *read = right.head;
	for(int i =0 ;i<right.capacity();i++)
    {
      //cout<<read->value<<endl;
      pushBack(read->value);
      read=read->next;
      //displayList();
    }
  //cout<<"Kill fucking 56"<<endl;
    //displayList();
  //read->next=nullptr;
  //pushBack(read->value);
  
  //displayList();
	return *this;
}

template<class T>
bool ListCollection<T>::isValid(int element) const {
	bool status;

	if (element < 0 || element >= capacity())
  {
		status = false;
  }
	else
  {
		status = true;
  }
	return status;
}

template<class T>
void ListCollection<T>::setElement(int element, T value) {
  ListNode *read=head;
	if (isValid(element))
  {
		for(int i = 0; i < element; i++)
      {
        read=read->next;
      }
    read->value=value;
  }
}

template<class T>
T ListCollection<T>::getElement(int pos) const {
	ListNode *read=head;
	if (isValid(pos))
  {
		for(int i = 0; i < pos; i++)
      {
        read=read->next;
      }
    return read->value;
  }
}

template<class T>
void ListCollection<T>::displayList(bool nl) const {
  
  ListNode *read = head;
  
  if(nl)
  {
    while(read!=nullptr)
      {
        cout<<read->value<<" ";
        read=read->next;
      }
    cout<<endl;
  }
  else
  {return;}
}

template<class T>
void ListCollection<T>::resize(int sz) {
  if(sz>size())
  {return;}
  else
  {
    ListNode *read = new ListNode;
    ListNode *newList= new ListNode;
    ListNode *temp = new ListNode;
    //numCapacity=sz;
    read = head;
    head = newList;
    for(int i = 0; i<sz;i++)
    {
      *temp=new ListNode;
      *newList=*read->value;
      *read=*read->next;
      newList->next=*temp;
      newList=newList->next;
        
    }
  }
  //delete[] read;
}

template<class T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection &right) {
	ListCollection<T> newList();
   ListNode *read =head;
	for(int i=0;i<size();i++)
    {
      newList.appendNode(*read->value);
      *read=read->next;
    }
  *read =right.head;
    for(int i=0; i<right.size();i++)
      {
        newList.insertOrdred(read->value);
        *read = read->next;
      }
  //newList.numCapacity = right.numCapacity + numCapacity;

	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b, int e) {
	if(b<0)
  {b=0;}
  if(e>=size())
  {e=size()-1;}
  ListCollection newList;
  ListNode *read = new ListNode;
  *read=*head;
  
  for(int i=0; i<=e;i++)
    {
      if(i>=b)
      {newList.pushBack(read->value);}
      if(read->next)
      *read=*read->next;
      //cout<<read;
    }
  //read->next=nullptr;
	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b) {
	ListCollection ans;
  ans = sublist(b, size() - 1);
  return ans;
}


template<class T> 
const ListCollection<T> ListCollection<T>::sort() {
  ListCollection<T> newList;
  ListNode *nodePtr = head;

  
  for(int i =0;i<size();i++)
    {
      newList.pushFront(nodePtr->value);
      nodePtr=nodePtr->next;
    }
  
  ListNode *newNode = newList.head;
  nodePtr = newList.head;
  //nodePtr=nodePtr->next;
  
  for(int i=0;i<size();i++){
    for(int j=0;j<size()-i;j++){
      
      if(nodePtr->value <  newNode->value){
        
        T temp = nodePtr->value;
        nodePtr->value = newNode->value;
        newNode->value = temp;
        
      }
      nodePtr=nodePtr->next;
      newNode=newNode->next;

      }
    
    newNode = newList.head;
    nodePtr = newList.head->next;
  }
  return newList;
}


template<class T>
int ListCollection<T>::capacity() const {
		int count = 0;
	ListNode *nodePtr = new ListNode;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		count++;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return count;
}

template<class T>
void ListCollection<T>::pushFront(T elt) {//
  
  
  ListNode *nNode = new ListNode;
  nNode->value=elt;
  //cout<<nNode->value<<endl;
  nNode->next=head;
  head=nNode;
  //numCapacity++;
}

template<class T>
void ListCollection<T>::pushBack(T elt) {
  ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

	// Allocate a new node and store newValue there.
	newNode = new ListNode;
  newNode->value=elt;
  newNode->next=nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
  //numCapacity++;
}

template<class T>
T ListCollection<T>::popFront() {
	T val=head->value;
  ListNode* NodeHold = head;
  head=head->next;
  delete NodeHold;
  //numCapacity--;
	return val;
}

template<class T>
T ListCollection<T>::popBack() {
  ListNode *read2=head;
  T val;
  //cout<<"Size at start "<<size()<<endl;
  while((read2->next)->next)//Check
    {
      //cout<<"Kachow"<<endl;
      read2=read2->next;
    }
  val=(read2->next)->value;
  read2->next=nullptr;
 
  //cout<<"Size at end "<<size()<<endl;
	return val;
  }

template<class T>
void ListCollection<T>::insert(int pos, T elt) {
	ListNode *read =head;
  ListNode *newNode = new ListNode;
  if(pos<=0)
  {
    pushFront(elt);
    return;
  }
  	if(pos>=size()-1)
  {
    pushBack(elt);
    return;
  }
  for(int i=0; i<pos-2; i++)
    {
      read=read->next;
    }
  newNode->value=elt;
  newNode->next=read->next;
  read->next=newNode;
  
}

template<class T>
void ListCollection<T>::remove(int pos) {
	if (!isValid(pos))
  {return;}
  if(pos==size()-1)
  {
    popBack();
    return;
  }
  if(pos==0)
  {
    popFront();
    return;
  }
  
  
  ListNode *read = new ListNode;
  ListNode *read2 = new ListNode;
  *read=*head;
  

	for(int i=0;i<pos-1;i++)
    {
      *read=*read->next;
    }
  
  *read2=*read;
  read2=read2->next;
  *read->next=*read2->next;
  //delete read2;
	//numCapacity--;
}

#endif
