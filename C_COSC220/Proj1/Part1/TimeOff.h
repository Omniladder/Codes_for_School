#ifndef TimeOff_H_
#define TimeOff_H_

#include <iostream>
#include "NumDays.h"

using namespace std;

class TimeOff
{
  private:
  NumDays maxSickDays;
  NumDays sickTaken;
  NumDays maxVacation;
  NumDays vacTaken;
  NumDays maxUnpaid;
  NumDays unpaidTaken;
  string name;
  int idNum;

  public:

  TimeOff();

  void setMaxSickDays(double);//
  void setSickTaken(double);
  void setMaxVacation(double);//
  void setVacTaken(double);//
  void setMaxUnpaid(double);//
  void setName(string);//
  void setId(int);//
  void setUnpaidTaken(double);

  double getMaxSickDays();
  double getSickTaken();
  double getMaxVacation();
  double getVacTaken();
  double getMaxUnpaid();
  string getName();
  int getId();

};

#endif
