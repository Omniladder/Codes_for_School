#include <iostream>
using namespace std;
#include "student.h"

int main()
{
  Student s1;
  Course cHolder;
  string sHolder;
  int iHolder;
  int temp;
  int intHolder;
  double dHolder;
  cout<<"\nWhat is this students name\n";
  cin>>sHolder;
  s1.setName(sHolder);
  cout<<"\nWhat is this students id\n";
  cin>>iHolder;
  s1.setId(iHolder);
  cout<<"\nHow many classes does this student have\n";
  cin>>intHolder;
  for(int i = 0; i<intHolder;i++)
    {
      cout<<"\nWhat is the name of class #"<<i+1<<"\n";
      cin>>sHolder;
      cHolder.setName(sHolder);

      cout<<"\nWhat is the code of class #"<<i+1<<"\n";
      cin>>temp;
      cHolder.setCode(temp);

      for(int j = 0; j<3;j++)
        {
          cout<<"\nWhat was the grade of test #"<<j+1<<"in class #"<<i+1<<"\n";
          cin>>dHolder;
          cHolder.setTest(j, dHolder);
        }
      s1.addCourse(cHolder);
    }
  cout<<"\nHow many Courses would you like deleted\n";
  cin>>intHolder;

  for(int i=0;i<intHolder;i++)
    {
      cout<<"\nWhat is the code of the "<<i+1<<"th class you want deleted \n";
      cin>>temp;
      cout<<"\nWhat is the name of the "<<i+1<<"th class you want deleted \n";
      cin>>sHolder;
      cHolder.setCode(temp);
      cHolder.setName(sHolder);
      s1.deleteCourse(cHolder);
    }

  cout<<"\n\n"<<s1;
  return 1;
}
