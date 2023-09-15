 #ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

 #include <iostream>
 #include <cstdlib>

using namespace std;

template <class T>
 class ListCollection
 {
 private:
 T *list; // Pointer to the array.
 int numElements; // Number of elements.
 int numCapacity; // Maximum number of elements.
 bool isValid(T element) const // Validates subscripts.//
{
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}
 void resize(int size) // Resizes list, moved to private.//
{
  T * nlist= new T [size];

  for(int i =0 ; i<numElements-1; i++)
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
  list = new T[size];
  //numElements =size;
  //cout<<"Trigger 2"<<endl;
  for(int i = 0;i<size;i++)
    {
      list[i]=nlist[i];
    }
  numCapacity=size;
  delete[] nlist;
}

  void setNumElements(int v)
{
  if(v<0)
  {
    v=0;
  }
  if(v>numCapacity)
  {
    v=numCapacity;
  }
  numElements=v;
}

 public:
 ListCollection(int sz = 10) // Constructor//
{
  list = new T[sz];
  numElements=0;
  numCapacity=sz;
}

  ~ListCollection() // Destructor//
{
  delete[] list;
}
 void setElement(int loc, T value) // Sets an element to a value//
{
	if (loc>numElements-1)
  {
    loc = numElements-1;
  }
  else
  {
	if(loc<0)
  {loc = 0;}
  else
    {
    list[loc] = value;
    }
  }
}
 T getElement(int element) const // Returns an element//
{
	if (element>numElements-1)
  {
    element = numElements-1;
  }
	if(element<0)
  {element = 0;}
  return list[element];
}
 void displayList(bool nl = true) const // Display list//
{
  if(nl)
  {
	for (int i = 0; i < numElements; i++)
		cout << list[i] << " ";
	cout << endl;
  }

}

 ListCollection(const ListCollection &obj)//
{
	numCapacity = obj.numCapacity;
  numElements = obj.numElements;
	list = new T[numCapacity];
	for (int i = 0; i < obj.numElements; i++)
		list[i] = obj.list[i];
}
 const ListCollection operator=(const ListCollection &right)//
{
	delete[] list;
	numElements = right.numElements;
  numCapacity = right.numCapacity;
	list = new T[numCapacity];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}

 // Updated functions
 const ListCollection operator+(const ListCollection &right)//
{
  ListCollection nlist( numCapacity+right.numCapacity );
  for(int i = 0 ; i<numElements;i++)
    {
      nlist.setElement(i,getElement(i));
    }
  for(int j = numElements ; j<numElements+right.numElements;j++)
    {
      nlist.setElement(j,right.getElement(j-numElements));
    }
  return nlist;
}
 const ListCollection sublist(int start, int finish)//
{

  if(finish>numElements)
  {
    finish=numElements;
  }

  ListCollection nlist(this->numCapacity);
  nlist.numElements=finish-start+1;
  for(int i = 0; i<finish-start+1;i++)
    {
      //if(i+start>numElements)

      {nlist.setElement(i,getElement(i+start));}
      //cout<<" Get Element is"<<nlist.getElement(i)<<"\n";

    }

  return nlist;
}
 const ListCollection sublist(int finish)//
{
  if(finish>numElements)
  {
    finish=numElements;
  }

  ListCollection nlist(this->numCapacity);
   nlist.numElements=numElements-finish;
  for(int i = finish; i<numElements;i++)
    {
      nlist.setElement(i-finish,getElement(i));
      //cout<<"Get Element "<<nlist.getElement(i)<<"\n";
    }

  //nlist.numElements=finish;

  return nlist;
}
 const ListCollection sort()
{
  T temp;
  ListCollection newarr (numCapacity);
  newarr.setNumElements(numElements);
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
            newarr.setElement(j-1, newarr.getElement(j));
            newarr.setElement(j, temp);

          }

        }

    }

  return newarr;
}
 // New functions
 void clear()
{
  numElements=0;
  delete[] list;
  list = new T[numCapacity];
}
 int size()
{return numElements;}
 int capacity()
{return numCapacity;}
 void pushFront(T v)
{
  T temp;
  numElements++;
  //cout<<"trigger 1";
  if(numElements>numCapacity)
  {
    this->resize(numCapacity*2);
  }
  for(int i = 0;i<=numElements;i++)
    {
      temp=list[numElements-i];
      list[numElements-i]=list[numElements-i-1];
      list[numElements-i-1]=temp;
      //list[numElements-i]=
    }

  list[0]=v;
}
 void pushBack(T v)
{
  numElements++;
  //cout<<"Trigger";
  if(numElements>numCapacity)
  {

    this->resize(numCapacity*2);
    cout<<"Trigger 2"<<endl;
  }
  list[numElements-1]=v;
}

 int popFront()
{
  T temp=list[0];
  list[0]=0;
  return temp;
}

 int popBack()
{
  T temp=list[numElements-1];
  //numElements--;
  list[numElements-1]=0;
  return temp;
}
 void insertOrdred(T v)
{
  numElements++;
   if(numElements>numCapacity)
  {
    this->resize(numCapacity*2);
  }
  list[numElements-1]=v;
  *this = sort();
}
 void removeElement(T Element)
{
  int temp = -1;
  for(int i=0; i<numElements;i++)
    {
      if(list[i]==Element)
      {
        temp=i;
        break;
      }
    }
  remove(temp);
}
 void insert(int loc, T v)
{
  if(loc<0)
  {
    loc=0;
  }
  if(loc>=numElements)
  {
    pushBack(v);
  }
  else
  {
  list[loc]=v;
  }
}
 void remove(int loc)
{
  if(!(loc>numElements||loc<0))
  {
    list[loc]=list[numElements-1];
    //list[numElements-1]=0;
      numElements--;
    *this = sort();
  }
}

 };

#endif
