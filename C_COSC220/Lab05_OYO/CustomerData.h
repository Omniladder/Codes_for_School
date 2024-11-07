#ifndef CustomerData_H_
#define CustomerData_H_

#include "PersonData.h"
#include <iostream>

using namespace std;

class CustomerData : public PersonData
{
private:
	int CustomerNumber;
	char MailingList;

public:
	void setCustomerNumber(int);
	void setMailingList(char);
	int getCustNum();
	bool getMailList();
	virtual void PrintRecord();
	virtual string getRecord();

};



#endif