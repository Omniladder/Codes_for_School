#include "ListCollection.h"


using namespace std;
ListCollection::ListCollection(int sz)
{
  list = new int[sz];
  numElements=0;
  numCapacity=sz;
}

ListCollection::~ListCollection(void)
{
  delete[] list;
}

void ListCollection::resize(int size)
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
  //numElements =size;
  for(int i = 0;i<size;i++)
    {
      list[i]=nlist[i];
    }
  numCapacity=size;
  delete[] nlist;
}

bool ListCollection::isValid(int element) const {
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

void ListCollection::setElement(int loc, int value) {
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

int ListCollection::getElement(int element) const {
	if (element>numElements-1)
  {
    element = numElements-1;
  }
	if(element<0)
  {element = 0;}
  return list[element];
}


void ListCollection::displayList(bool nl) const {
  if(nl)
  {
	for (int i = 0; i < numElements; i++)
		cout << list[i] << " ";
	cout << endl;
  }

}

ListCollection::ListCollection(const ListCollection &obj) {
	numCapacity = obj.numCapacity;
  numElements = obj.numElements;
	list = new int[numCapacity];
	for (int i = 0; i < obj.numElements; i++)
		list[i] = obj.list[i];
}

const ListCollection ListCollection::operator=(const ListCollection &right) {
	delete[] list;
	numElements = right.numElements;
  numCapacity = right.numCapacity;
	list = new int[numCapacity];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}


const ListCollection ListCollection::operator+(const ListCollection &right)
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


const ListCollection ListCollection::sublist(int start, int finish)
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

const ListCollection ListCollection::sublist(int finish)
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

const ListCollection ListCollection::sort()
{
  int temp;
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

void ListCollection::setNumElements(int v)
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


void ListCollection::clear()
{
  numElements=0;
  delete[] list;
  list = new int[numCapacity];
}

int ListCollection::size()
{return numElements;}

int ListCollection::capacity()
{return numCapacity;}

void ListCollection::pushFront(int v)
{
  int temp;
  numElements++;
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

void ListCollection::pushBack(int v)
{
  numElements++;
  if(numElements>numCapacity)
  {
    this->resize(numCapacity*2);
  }
  list[numElements-1]=v;
}

int ListCollection::popFront()
{
  int temp=list[0];
  list[0]=0;
  return temp;
}

int ListCollection::popBack()
{
  int temp=list[numElements-1];
  //numElements--;
  list[numElements-1]=0;
  return temp;
}

void ListCollection::insertOrdred(int v)
{
  numElements++;
   if(numElements>numCapacity)
  {
    this->resize(numCapacity*2);
  }
  list[numElements-1]=v;
  *this = sort();
}

void ListCollection::insert(int loc,int v)
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

void ListCollection::remove(int loc)
{
  if(!(loc>numElements||loc<0))
  {
    list[loc]=list[numElements-1];
    //list[numElements-1]=0;
      numElements--;
    *this = sort();
  }
}

void ListCollection::removeElement(int Element)
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
