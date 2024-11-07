#include <iostream>
#include <stack>
#include <sstream>


using namespace std;

int main() {
  string input;
 cout << "Enter Expression: ";
  stack<string> tokens2;
   getline(cin, input);
  string token;
  stringstream inputstream(input);
  stack<string> set1;
  stack<string> set2;
  bool delimit = true;
  while(getline(inputstream, token, ' '))
    {
      if(token=="{"||token=="["||token=="(")
      {set1.push(token);}

      if(token=="}"||token=="]"||token==")")
      {set2.push(token);}
    }
  
    
  int size = set1.size();
  for(int i = 0; i<size;i++)
    {
      //cout<<"Triggered"<<endl;
      if(set1.size()!=set2.size())
      {delimit=false; break;}
      if((set1.top()=="{"&&set2.top()!="}")||(set1.top()=="["&&set2.top()!="]")||(set1.top()=="("&&set2.top()!=")"))
      {delimit=false; break;}

        set1.pop();
        set2.pop();
    }

  
  if(delimit==true)
  {
    cout<<"Delimiter is Balanced"<<endl;
  }
  else
  {
    cout<<"Delimiter is Unbalanced"<<endl;
  }
}
