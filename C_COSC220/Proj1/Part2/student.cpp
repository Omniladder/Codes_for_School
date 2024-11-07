#include <iostream>
#include "student.h"
using namespace std;

Student::Student()
{
  name = "null";
  id=0;
 Classes = new Course[size];
}

Student::Student(int i,string n)
{
  name = n;
  id=i;
 Classes = new Course[size];
}

Student::Student(Student &right)
{
  name=right.name;
  id=right.id;
  Classes = new Course[size];
  for(int i = 0 ; i<size;i++)
    {
      *(Classes+i)=right.Classes[i];
    }
}

void Student::setId(int i)
{id=i;}
void Student::setName(string i)
{name=i;}
int Student::getId()
{return id;}
string Student::getName()
{return name;}
int Student::getSize()
{return size;}
Course Student::getClass(int loc)
{
  return *(Classes+loc);
}

void Student::addCourse(Course Class)
{
  Course *temp = new Course [size];

  for(int i=0;i<size;i++)
    {

      *(temp+i)=*(Classes+i);

    }

  delete[] Classes;
  size++;
  Classes = new Course[size];
  for(int i=0;i<size-1;i++)
    {
      *(Classes+i)=*(temp+i);
       //cout<<" Set Class to "<<i<<" to "<<(Classes+i)->getCode();//Works
    }
  *(Classes+size-1)=Class;
  delete[] temp;
}




void Student::deleteCourse(Course Class)
{
  int counter =0;
  for(int i = 0; i<size;i++)
    {
      if(*(Classes+i)==Class)
        {
          counter++;
        }
    }

  Course *temp= new Course[size-counter];

  int counter2=0;
  for(int i=0;i<size;i++)
    {
      if(!(*(Classes+i)==Class))
      {
        *(temp+counter2)=*(Classes+i);
        counter2++;
      }
    }
    delete[] Classes;
    size-=counter;
     Classes = new Course[size];

      for(int i =0;i<size;i++)
        {
          *(Classes+i)=*(temp+i);
        }


}







Student Student:: operator = (Student right)
{
  Student temp;
  temp.name=right.getName();
  temp.id=right.getId();
  for(int i=0;i<right.getSize();i++)
    {
      temp.addCourse(right.getClass(i));
    }
  return temp;
}


ostream &operator << (ostream &out,  Student const &right)
{
  out<<"Name: "<<right.name<<" ID: "<<right.id<<"\n";
  if(right.size!=0)
  {
    for(int i = 0; i<right.size;i++)
      {
        //cout<<(right.Classes+i)->getCode();
        out<<*(right.Classes+i)<<"\n";
      }
    }
  return out;
}
