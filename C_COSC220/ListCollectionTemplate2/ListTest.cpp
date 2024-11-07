#include <iostream>
#include "ListCollection.h"
#include "FeetInches.h"

using namespace std;

void setFeetInches(FeetInches &f, int feet, int inches)
{
    f.setFeet(feet);
    f.setInches(inches);
}

int main()
{
    ListCollection<FeetInches> l1;
    FeetInches f(5, 2);

    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.pushFront(f);
    setFeetInches(f, 3, 3);
    l1.pushFront(f);
    setFeetInches(f, 7, 9);
    l1.pushFront(f);
    setFeetInches(f, 2, 17);
    l1.pushFront(f);
    setFeetInches(f, 1, 4);
    l1.pushFront(f);

    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    cout << endl;

    setFeetInches(f, 55, 2);
    l1.pushBack(f);
    setFeetInches(f, 123, 7);
    l1.pushBack(f);
    setFeetInches(f, 90, 9);
    l1.pushBack(f);
    setFeetInches(f, 5, 1);
    l1.pushBack(f);
    setFeetInches(f, 7, 7);
    l1.pushBack(f);
    setFeetInches(f, 4, 2);
    l1.pushBack(f);
    
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    l1 = l1.sort();
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;

    setFeetInches(f, 1234, 10);
    l1.pushBack(1234);
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    cout << endl;
    
    cout << l1.popFront() << endl;
    cout << l1.popFront() << endl;
    cout << l1.popBack() << endl;
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    l1.clear();
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;

    cout << endl;
    
    setFeetInches(f, 3, 3);
    l1.insertOrdred(f);
    setFeetInches(f, 7, 9);
    l1.insertOrdred(f);
    setFeetInches(f, 2, 17);
    l1.insertOrdred(f);
    setFeetInches(f, 1, 4);
    l1.insertOrdred(f);
    setFeetInches(f, 55, 2);
    l1.insertOrdred(f);
    setFeetInches(f, 123, 7);
    l1.insertOrdred(f);
    setFeetInches(f, 90, 9);
    l1.insertOrdred(f);
    setFeetInches(f, 5, 1);
    l1.insertOrdred(f);
    setFeetInches(f, 7, 7);
    l1.insertOrdred(f);
    setFeetInches(f, 4, 2);
    l1.insertOrdred(f);
    
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;

    cout << endl;
    
    setFeetInches(f, 90, 9);
    l1.removeElement(f);
    setFeetInches(f, 7, 9);
    l1.removeElement(f);
    
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    setFeetInches(f, 741, 9);
    l1.removeElement(f);
    
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    cout << endl;
    
    ListCollection<FeetInches> l2 = l1.sublist(1, 6);
    l2.displayList(true);
    cout << l2.size() << "  " << l2.capacity() << endl;
    
    setFeetInches(f, 7, 1);
    l2.insertOrdred(30);
    
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    l2.displayList(true);
    cout << l2.size() << "  " << l2.capacity() << endl;

    cout << endl;
    
    ListCollection<FeetInches> l3 = l1.sublist(4);
    l3.displayList(true);
    cout << l3.size() << "  " << l3.capacity() << endl;
    
    cout << endl;
    
    cout << l3.getElement(2) << endl;
    l3.displayList(true);
    cout << l3.size() << "  " << l3.capacity() << endl;
    
    setFeetInches(f, 17, 2);
    l3.setElement(2, f);
    l3.displayList(true);
    cout << l3.size() << "  " << l3.capacity() << endl;

    cout << endl;
    
    l3.remove(2);
    l3.displayList(true);
    cout << l3.size() << "  " << l3.capacity() << endl;
    
    setFeetInches(f, 321, 7);
    l3.insert(1, f);
    l3.displayList(true);
    cout << l3.size() << "  " << l3.capacity() << endl;

    setFeetInches(f, 0, 9);
    l3.insert(100, f);
    l3.displayList(true);
    cout << l3.size() << "  " << l3.capacity() << endl;
    
    return 0;
}
