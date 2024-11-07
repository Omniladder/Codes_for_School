#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

IntegerList::IntegerList(int size) {
  cout<<"Inside Constructor \n";
	list = new int[size];
	numElements = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
}

IntegerList::~IntegerList() {
  cout<<"Inside Deconstructor \n";
	delete[] list;
}

IntegerList::IntegerList(const IntegerList &obj) {
  cout<<"Inside Copy \n";
	numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

const IntegerList IntegerList::operator=(const IntegerList &right) {
	delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}

bool IntegerList::isValid(int element) const {
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

void IntegerList::setElement(int element, int value) {
	if (element>numElements-1)
  {
    element = numElements-1;
  }
	if(element<0)
  {element = 0;}
  list[element] = value;
}

int IntegerList::getElement(int element) const {
	if (element>numElements-1)
  {
    element = numElements-1;
  }
	if(element<0)
  {element = 0;}
  return list[element];
}

void IntegerList::displayList() const {
	for (int i = 0; i < numElements; i++)
		cout << list[i] << " ";
	cout << endl;
}

int& IntegerList::operator[](const int &sub) {
  cout<<"[] has been called on index "<<sub<<" \n";
	if(sub>=numElements)
  {
    return list[numElements-1];
  }
  if(sub<0)
  {
    return list[0];
  }
	return list[sub];

}


const IntegerList IntegerList::operator+(const IntegerList &right)
{
  cout<<"Entered + operator \n";
  IntegerList nlist( numElements + right.numElements );
  for(int i = 0 ; i<numElements;i++)
    {
      nlist.setElement(i,getElement(i));
    }
  for(int j = numElements ; j<numElements+right.numElements;j++)
    {
      nlist.setElement(j,right.getElement(j-numElements));
    }
  cout<<"Exiting + operator \n";
  return nlist;
}


void IntegerList::resize(int size)
{
  int * nlist= new int [size];
  for(int i =0 ; i<size; i++)
    {
      if(i<numElements)
      {
        nlist[i]=list[i];
      }
      else
      {
        nlist[i]=0;
      }
    }
  delete[] list;
  list = new int[size];
  numElements =size;
  for(int i = 0;i<size;i++)
    {
      list[i]=nlist[i];
    }
  delete[] nlist;
}

const IntegerList IntegerList::sublist(int start, int finish)
{
  if(finish>numElements)
  {
    finish=numElements;
  }
  IntegerList nlist(finish-start+1);
  for(int i = 0; i<finish-start+1;i++)
    {
      if(i+start<numElements)
      {nlist.setElement(i,getElement(i+start));}


    }
  return nlist;
}

const IntegerList IntegerList::sublist(int finish)
{IntegerList nlist(finish+1);
  for(int i = 0; i<finish+1;i++)
    {
      nlist.setElement(i,getElement(i));
    }
  return nlist;
}

const IntegerList IntegerList::sort()
{
  int temp;
  IntegerList newarr= (numElements);
  for(int i = 0; i<numElements;i++)
    {
      newarr.setElement(i,list[i]);
    }
  for(int i = 0; i<numElements; i++)
    {
      for(int j = 1; j<numElements-i; j++)
        {
          if(newarr.getElement(j)<newarr.getElement(j-1))
          {
            temp = newarr.getElement(j-1);
            newarr.setElement(j-1, j);
            newarr.setElement(j, temp);

          }

        }

    }
  return newarr;
}
