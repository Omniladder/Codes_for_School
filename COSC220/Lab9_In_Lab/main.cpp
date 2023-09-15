#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

//#include "ListCollection.h"
using namespace std;

int main()
{
 
 // Must have spaces between tokens.

 string input;
 cout << "Enter a postfix expression: ";
 getline(cin, input);

 stack<string> tokens;
  stack<string> tokens2;
 stringstream inputstream(input);
 string token;

 // Tokenizing w.r.t. space ’ ’
 while(getline(inputstream, token, ' '))
 tokens2.push(token);
  
  int size = tokens2.size();
  for(int i = 0; i<size;i++)
    {
      tokens.push(tokens2.top());
      tokens2.pop();
    }
  

  string* arr = new string[3];
  while(!(tokens.size()<=1))
    {
      //cout<<tokens2.size()<<endl;
      
      arr[0]=tokens.top();
      tokens.pop();
      arr[1]=tokens.top();
      tokens.pop();
      arr[2]=tokens.top();
      tokens.pop();
      //cout<<"triggered"<<endl;
      //cout<<arr[0]<<arr[1]<<arr[2]<<endl;
      string temp;
    double num1;
    double num2;
    num2 = atof(arr[1].c_str());
    num1 = atof(arr[0].c_str());

      
    if(arr[2]=="/")
    {tokens.push(to_string(num1/num2));}
    else if(arr[2]=="*")
    {tokens.push(to_string(num1*num2));}
    else if(arr[2]=="+")
    {tokens.push(to_string(num1+num2));}
    else if(arr[2]=="-")
    {tokens.push(to_string(num1-num2));}
      else{tokens.push(arr[2]);}

      

    }
  
 // Printing the token vector
  cout<<tokens.top();
  return 1;
 }
