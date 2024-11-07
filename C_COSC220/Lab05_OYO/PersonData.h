#ifndef PersonData_H
#define PersonData_H

#include <iostream>

using namespace std;


class PersonData
{
private:
	string lastName = "null";
	string firstName = "null";
	string address = "null";
	string zip = "null";
	string phone = "null";
	string city = "null";
	string state = "null";

public:
	void setLast(string);
	void setFirst(string);
	void setName(string, string);
	void setAddress(string, string, string, string);
	void setAddress(string);
	void setZip(string);
	void setPhone(string);
	void setCity(string);
	void setState(string);
	string getLast();
	string getFirst();
	string getAddress();
	string getZip();
	string getPhone();
	string getCity();
	string getState();
	virtual void PrintRecord();
	virtual string getRecord();
};



#endif