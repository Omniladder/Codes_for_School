#include "PersonData.h"
#include <iostream>
#include <string>
using namespace std;

void PersonData::setLast(string Last)
{
	lastName = Last;
}
void PersonData::setFirst(string Last)
{
	firstName = Last;
}

void PersonData::setName(string First, string Last)
{
	firstName = First;
	lastName = Last;
}

void PersonData::setAddress(string Last, string City, string State, string Zip)
{
	address = Last;
	city = City;
	state = State;
	zip = Zip;
}
void PersonData::setAddress(string Last)
{
	address = Last;
}
void PersonData::setZip(string Last)
{
	zip = Last;
}
void PersonData::setPhone(string Last)
{
	phone = Last;
}
string PersonData::getLast()
{
	return lastName;
}
string PersonData::getFirst()
{
	return firstName;
}
string PersonData::getAddress()
{
	return address;
}
string PersonData::getZip()
{
	return zip;
}
string PersonData::getPhone()
{
	return phone;
}
void PersonData::setCity(string Last)
{
	city = Last;
}
void PersonData::setState(string Last)
{
	state = Last;
}

void PersonData::PrintRecord()
{
	cout << firstName << ", " << lastName << "\n" << address << "\n" << city << " " << state << " " << zip << "\n" << phone << "\n";
}

string PersonData::getRecord()
{
	string record;
	record.append(firstName);
	record.append(" / ");
	record.append(lastName);
	record.append(" / ");
	record.append(address);
	record.append(" / ");
	record.append(city);
	record.append(" / ");
	record.append(state);
	record.append(" / ");
	record.append(zip);
	record.append(" / ");
	record.append(phone);
	return record;
}