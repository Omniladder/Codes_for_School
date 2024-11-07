#ifndef NumDays_H_
#define NumDays_H_

#include <iostream>

using namespace std;

class NumDays
{
  private:
  int hours = 0;
  double days = 0;

  public:
  NumDays(int);
  NumDays();
  //~NumDays();
  int operator + (NumDays);
  int operator - (NumDays);
  void operator ++ ();
  void operator -- ();
  int getHours();
  void setHours(int);
  double getDays();
  void setDays(double);
};

#endif
