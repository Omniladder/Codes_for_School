#ifndef PROCESSREQUESTRECORD_CLASS
#define PROCESSREQUESTRECORD_CLASS

#include <iostream>
#include <string>

using namespace std;

class procReqRec
{
	public:
		// default constructor
		procReqRec();
		

		// constructor
		procReqRec(const string& nm, int p);

		// access functions
		int getPriority();
		string getName();

		// update functions
		void setPriority(int p);
		void setName(const string& nm);

		// for maintenance of a minimum priority queue
		friend bool operator< (const procReqRec& left,const procReqRec& right);
        friend bool operator> (const procReqRec& left,const procReqRec& right);

		// output a process request record in the format
		//   name: priority
		friend ostream& operator<< (ostream& ostr,const procReqRec& obj);

	private:
		string name;	// process name
		int priority;	// process priority
};

procReqRec::procReqRec()
{
    name = "";
    priority = 39;
}


procReqRec::procReqRec(const string& nm, int p)
{
    name = nm;
    priority = p;
}

int procReqRec::getPriority()
{
    return priority;
}

string procReqRec::getName()
{
    return name;
}

void procReqRec::setPriority(int p)
{
    priority = p;
}

void procReqRec::setName(const string& nm)
{
    name = nm;
}

bool operator < (const procReqRec& left,const procReqRec& right)
{
    if(left.priority > right.priority)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator > (const procReqRec& left,const procReqRec& right)
{
    if(left.priority < right.priority)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<< (ostream& ostr,const procReqRec& obj)
{
    ostr << obj.name <<": "<<obj.priority;
    return ostr;
}

#endif	// PROCESSREQUESTRECORD_CLASS