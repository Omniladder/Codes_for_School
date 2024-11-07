#include "CustomerData.h"
#include "PersonData.h"

#include <iostream>
using namespace std;

void CustomerData::setCustomerNumber(int Last)
{
	CustomerNumber = Last;
}
void CustomerData::setMailingList(char Last)
{
	MailingList = Last;
}
bool CustomerData::getMailList()
{
	return MailingList;
}
int CustomerData::getCustNum()
{
	return CustomerNumber;
}
void CustomerData::PrintRecord()
{
	PersonData::PrintRecord();
	cout << "Customer Number: " << CustomerNumber << "\n" << "On the Mailinglist: " << MailingList;

}

string CustomerData::getRecord()
{
	string record;
	record = PersonData::getRecord();
	record.append(" / ");
	record.append(to_string(CustomerNumber));
	record.append(" / ");
	return record;
}

