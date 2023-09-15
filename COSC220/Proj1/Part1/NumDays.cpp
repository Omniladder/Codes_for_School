#include <iostream>
#include "NumDays.h"





NumDays::NumDays(int h)
{
  hours = h;
 days=(double)hours/8;
}

NumDays::NumDays()
{
 hours=0;
  days=0;
}

int NumDays::operator + (NumDays right)
{
  return hours+right.hours;
}
int NumDays::operator - (NumDays right)
{
  return hours-right.hours;
}
void NumDays::operator ++ ()
{
  hours++;
  days=(double)hours/8;
}
void NumDays::operator -- ()
{
   hours--;
  days=(double)hours/8;
}

void NumDays::setDays(double d)
{
  days = d;
  hours = days*8;
  //cout<<" Set Days: "<<days;
}

void NumDays::setHours(int h)
{
  hours = h;
  days=(double)hours/8;
}

double NumDays::getDays()
{
  //cout<<" Get Days: "<<days<<" ";
  return days;
}

int NumDays::getHours()
{
  return hours;
}
