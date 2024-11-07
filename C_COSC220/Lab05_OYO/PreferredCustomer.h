#ifndef PREFERREDCUSTOMER_H_
#define PREFERREDCUSTOMER_H_

#include <iostream>

#include "CustomerData.h"
#include "PersonData.h"

using namespace std;

class PreferredCustomer : public CustomerData
{
private:
	double spent = 0;
	double discount = 0;

public:

	void purchaseAmount(double);//
	void discountLevel();//
	double getPurchase();//
	double getDiscount();//
	virtual void PrintRecord();//
	virtual string getRecord();//



};




#endif