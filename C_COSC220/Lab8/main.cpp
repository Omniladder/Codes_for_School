#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

/*
    Author: Don Spickler
    Creation Date: 10/12/2018
    Last Update: 10/12/2018
    Description: Testing program for the Stack abd Queue classes.
*/

void checkEmpty(Queue<int> q)
{
    if (q.isEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
}

void checkEmpty(Stack<double> s)
{
    if (s.isEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
}

int main()
{
    Stack<double> dstack;

	checkEmpty(dstack);
    cout << endl;

    dstack.push(7);
    dstack.push(25);
    dstack.push(-4);
    dstack.push(3);

    dstack.displayStack();

    cout << endl;
	checkEmpty(dstack);
    cout << endl;

    cout << dstack.pop() << endl;
    cout << dstack.pop() << endl;
    cout << endl;

    dstack.push(74);
    dstack.push(2);
    dstack.push(14);
    dstack.displayStack();
    cout << endl;

    cout << dstack.pop() << endl;
    cout << dstack.pop() << endl;
    cout << dstack.pop() << endl;
    cout << dstack.pop() << endl;
    cout << dstack.pop() << endl;
    cout << dstack.pop() << endl;
    dstack.displayStack();
    cout << endl;

	checkEmpty(dstack);
    cout << endl;

	for (int i = 0; i < 25; i++)
	    dstack.push(i);
    dstack.displayStack();
    cout << endl;

    cout << dstack.size() << endl;
	dstack.clear();
    cout << dstack.size() << endl;
	checkEmpty(dstack);
    cout << endl;

	dstack.push(3);
	dstack.push(5);
	dstack.push(7);
	dstack.push(9);
	dstack.push(11);
    dstack.displayStack();
    cout << endl;
    Stack<double> dstack2;
	checkEmpty(dstack2);
    cout << endl;
	dstack2 = dstack;//Here
  //cout<<dstack2.size()<<endl;
    dstack.displayStack();
    dstack2.displayStack();
    cout << endl;

	dstack.push(3);
	dstack.push(5);
	dstack.push(7);
	dstack.push(9);
	dstack.push(11);

	dstack2.push(2);
	dstack2.push(4);
	dstack2.push(6);
	dstack2.push(8);
	dstack2.push(10);
    dstack.displayStack();

    dstack2.displayStack();
    cout << endl;
 // return 1;
  //cout<<"Queue Start"<<endl;
	Queue<int> iqueue;

	iqueue.enqueue(5);
	iqueue.enqueue(7);
	iqueue.enqueue(12);
	iqueue.enqueue(-23);
	iqueue.enqueue(17);

	checkEmpty(iqueue);
    cout << endl;
  //cout<<"enqueue"<<endl;
	iqueue.displayQueue();
	cout << endl;

    cout << iqueue.dequeue() << endl;
    cout << iqueue.dequeue() << endl;

	iqueue.displayQueue();
    cout << endl;

	iqueue.enqueue(3);
	iqueue.enqueue(1);
	iqueue.enqueue(-67);
	iqueue.enqueue(32);
	iqueue.enqueue(7);

	iqueue.displayQueue();
    cout << endl;

	checkEmpty(iqueue);
    cout << endl;

	iqueue.clear();

    cout << iqueue.size() << endl;
	checkEmpty(iqueue);
    cout << endl;

	for (int i = 0; i < 25; i++)
		iqueue.enqueue(i);

	iqueue.displayQueue();
    cout << endl;

	Queue<int> iqueue2;

	iqueue2 = iqueue;

	iqueue.displayQueue();
	iqueue2.displayQueue();
    cout << endl;

	for (int i = 25; i > 0; i--)
		iqueue2.enqueue(i);

	iqueue.displayQueue();
	iqueue2.displayQueue();
    cout << endl;

    return 0;
}
