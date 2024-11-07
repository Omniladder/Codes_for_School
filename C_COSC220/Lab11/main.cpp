#include <iostream>
#include "BinaryTree.h"
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//  Function Prototypes


template<class T>
void bubble(T A[], int size);

template<class T>
void insertion(T A[], int size);

template<class T>
void selection(T A[], int size);

template<class T>
void merge(T A[], T Temp[], int startA, int startB, int end);

template<class T>
void mergeSort(T A[], T Temp[], int start, int end);

template<class T>
void mergeSort(T A[], int size);

template<class T>
void quickSort(T A[], int left, int right);

template<class T>
void quickSort(T A[], int size);

template<class T>
void treeSort(T A[], int size);

template<class T>
bool sorted(T A[], int size);

template<class T>
void print(T A[], int size);

template<class T>
void outputSorted(T A[], int size);

int main() {
	bool printarrays = false;
	printarrays = true;

	int size = 0;
	cout << "Input Array Size: ";
	cin >> size;

	int *A = new int[size];
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		A[i] = rand();

	outputSorted(A, size);

	if (printarrays)
		print(A, size);

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	//bubble(A, size);
	//insertion(A, size);
	//selection(A, size);

	//mergeSort(A, size);
	//quickSort(A, size);
  	treeSort(A,size);

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "Exe Time: " << time_span.count() << " seconds." << endl;

	if (printarrays)
		print(A, size);

	outputSorted(A, size);

	return 0;
}

// Sorting Algorithms

///////////////////////////////////////////////////////////

template<class T>
void bubble(T A[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				T temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

///////////////////////////////////////////////////////////

template<class T>
void insertion(T A[], int size) {
	for (int i = 0; i < size; i++) {
		int j = 0;
		T val = A[i];
		for (j = i; j > 0 && A[j - 1] > val; j--)
			A[j] = A[j - 1];

		A[j] = val;
	}
}

///////////////////////////////////////////////////////////

template<class T>
void selection(T A[], int size) {
	int minindex;

	for (int i = 0; i < size; i++) {
		minindex = i;
		for (int j = i; j < size; j++)
			if (A[j] < A[minindex])
				minindex = j;

		T val = A[i];
		A[i] = A[minindex];
		A[minindex] = val;
	}
}

///////////////////////////////////////////////////////////

template<class T>
void merge(T A[], T Temp[], int startA, int startB, int end) {
	int aptr = startA;
	int bptr = startB;
	int i = startA;

	while (aptr < startB && bptr <= end)
		if (A[aptr] < A[bptr])
			Temp[i++] = A[aptr++];
		else
			Temp[i++] = A[bptr++];

	while (aptr < startB)
		Temp[i++] = A[aptr++];

	while (bptr <= end)
		Temp[i++] = A[bptr++];

	for (i = startA; i <= end; i++)
		A[i] = Temp[i];
}

template<class T>
void mergeSort(T A[], T Temp[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(A, Temp, start, mid);
		mergeSort(A, Temp, mid + 1, end);
		merge(A, Temp, start, mid + 1, end);
	}
}

template<class T>
void mergeSort(T A[], int size) {
	T* Temp= new T[size];
	mergeSort(A, Temp, 0, size - 1);
	delete[] Temp;
}

///////////////////////////////////////////////////////////

template<class T>
void quickSort(T A[], int left, int right) {
	int i = left;
	int j = right;
	int mid = (left + right) / 2;

	T pivot = A[mid];

	while (i <= j) {
		while (A[i] < pivot)
			i++;

		while (A[j] > pivot)
			j--;

		if (i <= j) {
			T tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(A, left, j);

	if (i < right)
		quickSort(A, i, right);
}

template<class T>
void quickSort(T A[], int size) {
	quickSort(A, 0, size - 1);
}

///////////////////////////////////////////////////////////

//  Support functions

template<class T>
bool sorted(T A[], int size) {
	for (int i = 0; i < size - 1; i++)
		if (A[i] > A[i + 1])
			return false;

	return true;
}

template<class T>
void print(T A[], int size) {
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";

	cout << endl;
}

template<class T>
void outputSorted(T A[], int size) {
	if (sorted(A, size))
		cout << "Sorted" << endl;
	else
		cout << "Not Sorted" << endl;
}

template<class T>
void treeSort(T A[], int size)
{
  BinaryTree<T> tree;
  for(int i=0;i<size;i++)
    {tree.insertNode(A[i]);}
  tree.loadInOrder(A);
  
}
