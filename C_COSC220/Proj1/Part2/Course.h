#ifndef Course_H_
#define Course_H_

#include <iostream>
using namespace std;

class Course
{
  private:
  int code;
  string name;
  double tests[3];

  public:

  Course();
  Course(int,string,double,double,double);

  void setCode(int);
  void setName(string);
  void setTest(int,double);

  int getCode();
  string getName();
  double  getTest(int);

  friend ostream &operator << (ostream&,const Course&);

  void operator=(Course right);
  bool operator==(Course right);
};


#endif
