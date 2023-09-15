

#include "PreferredCustomer.h"
#include "CustomerData.h"
#include "PersonData.h"


#include <iostream>
#include <string>
using namespace std;

double PreferredCustomer::getPurchase()
{
    return spent;
}
double PreferredCustomer::getDiscount()
{
    return discount;
}
void PreferredCustomer::purchaseAmount(double s)
{
    if (s >= 0)
    {
        spent = s;
    }
    else
    {
        spent = 0;
    }
    discountLevel();
}
void PreferredCustomer::discountLevel()
{
    if (spent > 200)
    {
        discount = .05;
    }
    if (spent > 1000)
    {
        discount = .06;
    }
    if (spent > 1500)
    {
        discount = .07;
    }
    if (spent > 2000)
    {
        discount = .1;
    }
}

string PreferredCustomer::getRecord()
{
    string record;
    record = CustomerData::getRecord();
    record.append(" Spent: $");
    record.append(to_string(spent));
    record.append(" Discount is ");
    record.append(to_string(discount));
    return record;
}

void PreferredCustomer::PrintRecord()
{
    CustomerData::PrintRecord();
    cout << "\n this Customer Spent: $" << spent << " Their Discount is " << discount;
}