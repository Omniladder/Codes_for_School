#include "inf2pstf.h"
#include "d_tnode.h"
#include "d_tnodel.h"
#include "d_except.h"
#include "d_expsym.h"
#include <iostream>

using namespace std;

tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}


void prefixOutput(tnode<char> *exp)
{
    if(exp != NULL)
    {
        cout<<exp->nodeValue<<" ";
        prefixOutput(exp->left);
        prefixOutput(exp->right);
    }
} 


int main()
{
    string response;
    cout<<"Enter Expression ";
    cin>>response;
    cout<<endl<<endl;
    
    infix2Postfix expression;


	tnode<char> *tree;

    expression.setInfixExp(response);

	tree = buildExpTree(expression.postfix());

	cout<<"Prefix form ";
	prefixOutput(tree);
	cout<<endl<<endl;
    cout<<"Postfix form ";
	postorderOutput(tree," ");
	cout<<endl<<endl;
	

	displayTree(tree,7);


    return 0;
}