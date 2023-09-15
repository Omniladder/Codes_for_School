#include <iostream>
#include "TimeOff.h"


TimeOff::TimeOff()
{
  idNum=0;
  name="null";
   maxUnpaid.setDays(0);
  NumDays maxSickDays(0);
  NumDays vacTaken(0);
  NumDays sickTaken(0);
  NumDays maxVacation(0);
  NumDays unpaidTaken(0);
}



void TimeOff::setId(int i)
{idNum=i;}
void TimeOff::setName(string n)
{name=n;}
void TimeOff::setMaxUnpaid(double h)
{
  maxUnpaid.setDays(h);}
void TimeOff::setMaxSickDays(double s)
{//cout<<s;//Works
  maxSickDays.setDays(s);}

void TimeOff::setMaxVacation(double v)
{//cout<<v;
  //maxVacation.setDays(v);

  if(v<=240)
  {maxVacation.setDays(v);}
  else
  {maxVacation.setDays(240);}

  }

void TimeOff::setVacTaken(double v)
{vacTaken.setDays(v);}
void TimeOff::setSickTaken(double s)
{sickTaken.setDays(s);}
void TimeOff::setUnpaidTaken(double u)
{unpaidTaken.setDays(u);}


double TimeOff::getMaxUnpaid()
{return maxUnpaid.getDays();}
double TimeOff::getMaxSickDays()
{return maxSickDays.getHours();}
double TimeOff::getMaxVacation()
{return maxVacation.getDays();}
double TimeOff::getVacTaken()
{return vacTaken.getDays();}
double TimeOff::getSickTaken()
{return sickTaken.getDays();}
string TimeOff::getName()
{return name;}
int TimeOff::getId()
{return idNum;}
