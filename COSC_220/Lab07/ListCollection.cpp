#include <iostream>
#include "ListCollection.h"
#include "FeetInches.h"

using namespace std;

void setFeetInches(FeetInches &f, int feet, int inches) {
	f.setFeet(feet);
	f.setInches(inches);
}

int main() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Integer Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	ListCollection<int> l1;

	cout << l1.size() << "  " << l1.capacity() << endl;

	l1.pushFront(25);
	l1.pushFront(56);
	l1.pushFront(-7);
	l1.pushFront(10);
	l1.pushFront(33);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	cout << endl;

	l1.pushBack(55);
	l1.pushBack(-4);
	l1.pushBack(22);
	l1.pushBack(123);
	l1.pushBack(-47);
	l1.pushBack(12);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	l1 = l1.sort();
	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	l1.pushBack(1234);
	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	cout << endl;

	cout << l1.popFront() << endl;
	cout << l1.popFront() << endl;
	cout << l1.popBack() << endl;
	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	l1.clear();
	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	cout << endl;

	l1.insertOrdred(25);
	l1.insertOrdred(56);
	l1.insertOrdred(-7);
	l1.insertOrdred(10);
	l1.insertOrdred(33);
	l1.insertOrdred(55);
	l1.insertOrdred(-4);
	l1.insertOrdred(22);
	l1.insertOrdred(33);
	l1.insertOrdred(123);
	l1.insertOrdred(-47);
	l1.insertOrdred(33);
	l1.insertOrdred(12);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	cout << endl;

	l1.removeElement(22);
	l1.removeElement(33);
	l1.removeElement(122);
	l1.removeElement(-7);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	l1.removeElement(-47);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	l1.removeElement(-75);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;

	cout << endl;

	ListCollection<int> l2;
  l2 = l1.sublist(1, 6);
  l2.displayList();
	cout << l2.size() << "  " << l2.capacity() << endl;

	l2.insertOrdred(30);

	l1.displayList();
	cout << l1.size() << "  " << l1.capacity() << endl;
	l2.displayList();
	cout << l2.size() << "  " << l2.capacity() << endl;

	cout << endl;

	ListCollection<int> l3;
  l3 = l1.sublist(4);
	l3.displayList();
	cout << l3.size() << "  " << l3.capacity() << endl;
  
	cout << endl;

	cout << l3.getElement(2) << endl;
	l3.displayList();
	cout << l3.size() << "  " << l3.capacity() << endl;
  
	l3.setElement(2, 40);
	l3.displayList();
	cout << l3.size() << "  " << l3.capacity() << endl;
  
	cout << endl;

	l3.remove(4);
	l3.displayList();
	cout << l3.size() << "  " << l3.capacity() << endl;
  
	l3.insert(2, 17);
	l3.displayList();
	cout << l3.size() << "  " << l3.capacity() << endl;
  
	l3.insert(20, 27);
	l3.displayList();
	cout << l3.size() << "  " << l3.capacity() << endl;

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "FeetInches Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	ListCollection<FeetInches> FIl1;
	FeetInches f(5, 2);

	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	FIl1.pushFront(f);
	setFeetInches(f, 3, 3);
	FIl1.pushFront(f);
	setFeetInches(f, 7, 9);
	FIl1.pushFront(f);
	setFeetInches(f, 2, 17);
	FIl1.pushFront(f);
	setFeetInches(f, 1, 4);
	FIl1.pushFront(f);

	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	cout << endl;

	setFeetInches(f, 55, 2);
	FIl1.pushBack(f);
	setFeetInches(f, 123, 7);
	FIl1.pushBack(f);
	setFeetInches(f, 90, 9);
	FIl1.pushBack(f);
	setFeetInches(f, 5, 1);
	FIl1.pushBack(f);
	setFeetInches(f, 7, 7);
	FIl1.pushBack(f);
	setFeetInches(f, 4, 2);
	FIl1.pushBack(f);

	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	FIl1 = FIl1.sort();
	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	setFeetInches(f, 1234, 10);
	FIl1.pushBack(f);
	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	cout << endl;

	cout << FIl1.popFront() << endl;
	cout << FIl1.popFront() << endl;
	cout << FIl1.popBack() << endl;
	cout << endl;
	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	FIl1.clear();
	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	cout << endl;

	setFeetInches(f, 3, 3);
	FIl1.insertOrdred(f);
	setFeetInches(f, 7, 9);
	FIl1.insertOrdred(f);
	setFeetInches(f, 2, 17);
	FIl1.insertOrdred(f);
	setFeetInches(f, 1, 4);
	FIl1.insertOrdred(f);
	setFeetInches(f, 55, 2);
	FIl1.insertOrdred(f);
	setFeetInches(f, 123, 7);
	FIl1.insertOrdred(f);
	setFeetInches(f, 90, 9);
	FIl1.insertOrdred(f);
	setFeetInches(f, 5, 1);
	FIl1.insertOrdred(f);
	setFeetInches(f, 7, 7);
	FIl1.insertOrdred(f);
	setFeetInches(f, 4, 2);
	FIl1.insertOrdred(f);

	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	cout << endl;

	setFeetInches(f, 90, 9);
	FIl1.removeElement(f);
	setFeetInches(f, 7, 9);
	FIl1.removeElement(f);

	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	setFeetInches(f, 741, 9);
	FIl1.removeElement(f);

	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;

	cout << endl;

	ListCollection<FeetInches> FIl2;
  FIl2 = FIl1.sublist(1, 6);
	FIl2.displayList(true);
	cout << FIl2.size() << "  " << FIl2.capacity() << endl;

	setFeetInches(f, 7, 1);
	FIl2.insertOrdred(f);

	FIl1.displayList(true);
	cout << FIl1.size() << "  " << FIl1.capacity() << endl;
	FIl2.displayList(true);
	cout << FIl2.size() << "  " << FIl2.capacity() << endl;

	cout << endl;

	ListCollection<FeetInches> FIl3;
  FIl3 = FIl1.sublist(4);
	FIl3.displayList(true);
	cout << FIl3.size() << "  " << FIl3.capacity() << endl;

	cout << endl;

	cout << FIl3.getElement(2) << endl;
	FIl3.displayList(true);
	cout << FIl3.size() << "  " << FIl3.capacity() << endl;

	setFeetInches(f, 17, 2);
	FIl3.setElement(2, f);
	FIl3.displayList(true);
	cout << FIl3.size() << "  " << FIl3.capacity() << endl;

	cout << endl;

	FIl3.remove(2);
	FIl3.displayList(true);
	cout << FIl3.size() << "  " << FIl3.capacity() << endl;

	setFeetInches(f, 321, 7);
	FIl3.insert(1, f);
	FIl3.displayList(true);
	cout << FIl3.size() << "  " << FIl3.capacity() << endl;

	setFeetInches(f, 0, 9);
	FIl3.insert(100, f);
	FIl3.displayList(true);
	cout << FIl3.size() << "  " << FIl3.capacity() << endl;

	return 0;
}
