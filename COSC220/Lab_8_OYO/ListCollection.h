
#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class ListCollection {
private:
	T *list;
	int numElements;
	int numCapacity;
	bool isValid(int) const;
	void resize(int);

public:
	ListCollection(int sz = 10);
	~ListCollection();
	void setElement(int, T);
	T getElement(int) const;
	void displayList(bool nl = false) const;

	ListCollection(const ListCollection &obj);
	const ListCollection<T> operator=(const ListCollection &right);

	const ListCollection<T> operator+(const ListCollection &right);
	const ListCollection<T> sublist(int, int);
	const ListCollection<T> sublist(int);
	const ListCollection<T> sort();

	void clear();
	int size();
	int capacity();
	void pushFront(T);
	void pushBack(T);
	T popFront();
	T popBack();
	void insertOrdred(T);
	void removeElement(T);
	void insert(int, T);
	void remove(int);
  void input(string);
};

template<class T>
ListCollection<T>::ListCollection(int size) {
	if (size <= 0)
		size = 1;
	list = new T[size];
	numElements = 0;
	numCapacity = size;
}

template<class T>
ListCollection<T>::~ListCollection() {
	delete[] list;
}

template<class T>
ListCollection<T>::ListCollection(const ListCollection &obj) {
	numCapacity = obj.numCapacity;
	numElements = obj.numElements;
	list = new T[numCapacity];
	for (int i = 0; i < numCapacity; i++)
		list[i] = obj.list[i];
}

template<class T>
const ListCollection<T> ListCollection<T>::operator=(
		const ListCollection &right) {
	delete[] list;
	numCapacity = right.numCapacity;
	numElements = right.numElements;
	list = new T[numCapacity];
	for (int i = 0; i < numCapacity; i++)
		list[i] = right.list[i];

	return *this;
}

template<class T>
bool ListCollection<T>::isValid(int element) const {
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;

	return status;
}

template<class T>
void ListCollection<T>::setElement(int element, T value) {
	if (isValid(element))
		list[element] = value;
}

template<class T>
T ListCollection<T>::getElement(int pos) const {
	T defaultret;

	if (numElements == 0)
		return defaultret;

	if (pos < 0)
		return list[0];

	if (pos >= numElements)
		return list[numElements - 1];

	return list[pos];
}

template<class T>
void ListCollection<T>::displayList(bool nl) const {
	for (int i = 0; i < numElements; i++) {
		cout << list[i] << " ";
		if (nl)
			cout << endl;
	}
	if (!nl)
		cout << endl;
}

template<class T>
void ListCollection<T>::resize(int sz) {
	T *newArray = new T[sz];

	int min = sz;
	if (min > numCapacity)
		min = numCapacity;

	for (int i = 0; i < min; i++)
		newArray[i] = list[i];

	if (numElements > sz)
		numElements = sz;

	numCapacity = sz;

	delete[] list;
	list = newArray;
}

template<class T>
const ListCollection<T> ListCollection<T>::operator+(
		const ListCollection &right) {
	ListCollection<T> newList(numElements + right.numElements);

	for (int i = 0; i < numElements; i++)
		newList.list[i] = list[i];

	for (int i = 0; i < right.numElements; i++)
		newList.list[i + numElements] = right.list[i];

	newList.numElements = numElements + right.numElements;

	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b, int e) {
	if (b > e) {
		int temp = b;
		b = e;
		e = temp;
	}

	if (b < 0)
		b = 0;

	if (e < 0)
		e = 0;

	if (b >= numElements)
		b = numElements - 1;

	if (e >= numElements)
		e = numElements - 1;

	ListCollection<T> newList(e - b + 1);
	for (int i = 0; i < e - b + 1; i++)
		newList.list[i] = list[b + i];

	newList.numElements = e - b + 1;

	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b) {
	return sublist(b, numElements - 1);
}

template<class T>
const ListCollection<T> ListCollection<T>::sort() {
	ListCollection<T> newList(numElements);
	newList.numElements = numElements;
	for (int i = 0; i < numElements; i++)
		newList.list[i] = list[i];

	for (int i = numElements - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++) {
			if (newList.list[j] > newList.list[j + 1]) {
				T temp = newList.list[j];
				newList.list[j] = newList.list[j + 1];
				newList.list[j + 1] = temp;
			}
		}

	return newList;
}

template<class T>
int ListCollection<T>::size() {
	return numElements;
}

template<class T>
int ListCollection<T>::capacity() {
	return numCapacity;
}

template<class T>
void ListCollection<T>::pushFront(T elt) {
	if (numElements == numCapacity)
		resize(2 * numCapacity);

	for (int i = numElements - 1; i >= 0; i--)
		list[i + 1] = list[i];

	list[0] = elt;
	numElements++;
}

template<class T>
void ListCollection<T>::pushBack(T elt) {
	if (numElements == numCapacity)
		resize(2 * numCapacity);

	list[numElements] = elt;
	numElements++;
}

template<class T>
T ListCollection<T>::popFront() {
	T defaultret;

	if (numElements == 0)
		return defaultret;

	T retval = list[0];

	for (int i = 1; i < numElements; i++)
		list[i - 1] = list[i];

	numElements--;

	return retval;
}

template<class T>
T ListCollection<T>::popBack() {
	T defaultret;

	if (numElements == 0)
		return defaultret;

	T retval = list[numElements - 1];

	numElements--;

	return retval;
}

template<class T>
void ListCollection<T>::insertOrdred(T elt) {
	if (numElements == numCapacity)
		resize(2 * numCapacity);

	int pos = 0;
	while (pos < numElements && list[pos] < elt)
		pos++;

	if (pos == 0)
		pushFront(elt);
	else if (pos == numElements)
		pushBack(elt);
	else {
		for (int i = numElements; i >= pos; i--)
			list[i + 1] = list[i];

		list[pos] = elt;
		numElements++;
	}
}

template<class T>
void ListCollection<T>::removeElement(T elt) {
	int pos = 0;
	while (pos < numElements && list[pos] != elt)
		pos++;

	if (pos == numElements)
		return;

	for (int i = pos + 1; i < numElements; i++)
		list[i - 1] = list[i];

	numElements--;
}

template<class T>
void ListCollection<T>::insert(int pos, T elt) {
	if (numElements == numCapacity)
		resize(2 * numCapacity);

	if (pos >= numElements)
		pushBack(elt);
	else if (pos <= 0)
		pushFront(elt);
	else {
		for (int i = numElements; i >= pos; i--)
			list[i + 1] = list[i];

		list[pos] = elt;
		numElements++;
	}
}

template<class T>
void ListCollection<T>::remove(int pos) {
	if (!isValid(pos))
		return;

	for (int i = pos + 1; i < numElements; i++)
		list[i - 1] = list[i];

	numElements--;
}

template<class T>
void ListCollection<T>::clear() {
	numElements = 0;
}

template<class T>
void ListCollection<T>::input(string in)
{

  if(in == "/" || in == "*" || in == "+"|| in == "-")
  {
    string temp;
    double num1;
    double num2;
    temp = popBack();
    num2 = atof(temp.c_str());
    temp = popBack();
    num1 = atof(temp.c_str());
    if(in=="/")
    {pushBack(to_string((double)num1/num2));}
    if(in=="*")
    {pushBack(to_string((double)num1*num2));}
    if(in=="+")
    {pushBack(to_string((double)num1+num2));}
    if(in=="-")
    {pushBack(to_string((double)num1-num2));}
  }
  else
  {pushBack(in);}
}

#endif
