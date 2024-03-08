#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

//#include "ListCollection.h"


void print(queue<string> q)
{
  for(int i = 0; i<q.size();i++)
    {
      cout<<q.front()<<" ";
      q.push(q.front());
      q.pop();
    }
    cout<<endl;
}
string getElement(queue<string> &q, int element)
{
  string e;
  for(int i =0 ; i<q.size();i++)
    {
      if(i==element)
      {
        e=q.front();
      }
      q.push(q.front());
      q.pop();
    }
  return e;
}

void addElement(queue<string> &q,string element,int loc)
{
  if(loc<0)
  {
    loc=0;
  }
  
  if(loc>=q.size()-1)
  {
    
    q.push(element);
    return;
  }
  for(int i = 0 ;i < q.size()-1;i++)
    {
      if(loc==i)
      {
        q.push(element);
      }
      q.push(q.front());
      q.pop();
    }
}

void deleteElement(queue<string> &q,int loc)
{
  for(int i = 0; i < q.size()+1; i++)
    {
      if(i!=loc)
      {
        q.push(q.front());
      }
      q.pop();
    }
}

void calculate(queue<string> &q)
{
  int counter = 0;
  string op;
  string temp;
  double num1;
  double num2;
  
  while(counter<q.size())
    {
      
      
      if(getElement(q,counter)=="/"||getElement(q,counter)=="*"||getElement(q,counter)=="-"||getElement(q,counter)=="+")
      {
        
        temp = getElement(q,counter-1);
        num2 = atof(temp.c_str());
        temp = getElement(q,counter-2);
        num1 = atof(temp.c_str());
        op = getElement(q,counter);
        deleteElement(q,counter);
        deleteElement(q,counter-1);
        deleteElement(q,counter-2);
        
        if(op=="/")
        {
          addElement(q,to_string(num1/num2),counter-3);
        }
        if(op=="*")
        {
          addElement(q,to_string(num1*num2),counter-3);
        }
        if(op=="-")
        {
          addElement(q,to_string(num1-num2),counter-3);
        }
        if(op=="+")
        {
          addElement(q,to_string(num1+num2),counter-3);
         // cout<<counter-3<<"counter - 3"<<endl;
        }
        counter=-1;
      }
      //cout<<"Queue"<<endl;
      counter++;
    }
}


int main()
{
 
 // Must have spaces between tokens.

 string input;
 cout << "Enter a postfix expression: ";
 getline(cin, input);

  queue<string> tokens2;
 stringstream inputstream(input);
 string token;

 // Tokenizing w.r.t. space ’ ’
 while(getline(inputstream, token, ' '))
 tokens2.push(token);

  calculate(tokens2);
 // Printing the token vector
  print(tokens2);
  
 }
