#include <iostream>
#include "IntegerList.h"

using namespace std;

void PopulateList(IntegerList &L, int size)
{
  cout<<"Inside Populate 1 \n";
    for (int i = 0; i < size; i++)
        L[i] = i;
}

void PopulateList2(IntegerList L, int size)
{
  cout<<"Inside Populate 2 \n";
    for (int i = 0; i < size; i++)
        L[i] = i;
}

int main()
{
    IntegerList l1(7);

    IntegerList l2(17);

    for (int i = 0; i < 7; i++)
        l1[i] = i * i;

    PopulateList2(l1, 7);
  cout<<"Outside Populate 2 \n";
    PopulateList(l2, 17);
  cout<<"Outside Populate 1 \n";

    l1.displayList();
    l2.displayList();


    IntegerList l3 = l1 + l2;
    l3.displayList();

    l3[4] = 100;
    l3.displayList();

    IntegerList l4 = l3.sublist(3, 8);
    l4.displayList();

    IntegerList l5 = l3.sublist(8);
    l5.displayList();

    IntegerList l6 = l3.sublist(3, 800);
    l6.displayList();

    l6.resize(5);
    l4.resize(30);
    l6.displayList();
    l4.displayList();

    IntegerList l7 = l3.sort();
    l3.displayList();
    l7.displayList();

    IntegerList l8 = l7;
    l8.displayList();

    return 0;
}

//Populate 2 brings in integer list by reference although i changes because theirs a loop in the main getting all the squares
// 11,12
//the constructor for 14 15 16 and 17
//18

