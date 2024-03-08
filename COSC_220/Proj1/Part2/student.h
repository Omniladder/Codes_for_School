#ifndef Student_H_
#define Student_H_

#include <iostream>
#include "Course.h"
using namespace std;

class Student
{
  private:
  int id;
  string name;
  int size=0;
  Course *Classes;

  public:
  Student();
  Student(int,string);
  //~Student();
  Student(Student &right);

  bool operator == (Student right);
 Student operator=(Student right);
  friend ostream &operator << (ostream&,const Student&);

  void setId(int);
  void setName(string);
  int getId();
  string getName();
  int getSize();
  Course getClass(int);

  void addCourse(Course);
  void deleteCourse(Course);


};



#endif
