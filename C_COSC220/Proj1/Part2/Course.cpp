#include <iostream>
#include "Course.h"

using namespace std;

Course::Course()
{
  code=000;
  name="null";
  for(int i = 0 ; i<3; i++)
    {tests[i]=0;}
}

Course::Course(int c,string n,double e1,double e2,double e3)
{
  code=c;
  name=n;
  tests[0]=e1;
  tests[1]=e2;
  tests[2]=e3;
}


void Course::setCode(int c)
{code=c;}
void Course::setName(string n)
{name=n;}
void Course::setTest(int loc,  double score)
{
  tests[loc]=score;
}
int   Course::getCode()
{return code;}

string  Course::getName()
{return name;}

double Course::getTest(int loc)
{return tests[loc];}


ostream &operator << (ostream &out,  Course const &right)
{
  return out<<right.name << " " << right.code << " Scores: " << right.tests[0] << " " << right.tests[1] << " " <<  right.tests[2] << "\n";
}

void Course:: operator = (Course right)
{
  Course temp;
  name=right.getName();
  code=right.getCode();
  //cout<<" set to "<<right.getCode(); //Works:
  for(int i = 0; i<3;i++)
    {
      tests[i]=right.getTest(i);
    }

}

bool Course::operator == (Course right)
{
  if(code==right.code&&name==right.name)
  {
    return true;
  }
  else
  {
    return false;
  }
}
