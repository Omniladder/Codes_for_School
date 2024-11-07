#include <iostream>
#include "TimeOff.h"

using namespace std;
int main()
{
  TimeOff Employee;
  int month;
  cout<<"How Many Months has the employee months has this employee worked \n";
  cin>>month;
  //cout<<month;//Works
  //cout<< month*12+Employee.getMaxVacation(); //Works
  Employee.setMaxVacation(month*12+Employee.getMaxVacation());
  Employee.setMaxSickDays(month+Employee.getMaxSickDays());
  cout<<"Max Vacation Hours: "<<Employee.getMaxVacation()<<" Max Sick Hours "<<Employee.getMaxSickDays();
}
