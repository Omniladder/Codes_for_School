#include <iostream>
#include "ListCollection.h"

using namespace std;

int main() {
    ListCollection l1;

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

    l1.remove(22);
    l1.remove(33);
    l1.remove(122);
    l1.remove(-7);

    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.removeElement(-47);

    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.removeElement(-75);

    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    cout << endl;

    ListCollection l2 = l1.sublist(1, 6);
    l2.displayList();
    cout << l2.size() << "  " << l2.capacity() << endl;

    l2.insertOrdred(30);

    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;
    l2.displayList();
    cout << l2.size() << "  " << l2.capacity() << endl;

    cout << endl;

    ListCollection l3 = l1.sublist(4);
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

    return 0;
}
