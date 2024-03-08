char* myitoa(int x, char Inputs[])
{ int temp = x;
  int size = 0;
  while(temp!=0)
  { temp/=10;
  size++;} char ans[size];
  for(int i=0;i< size;i++)
 {ans[size - i -1] = (int)((x%10)+'0'); //removed (int) casting and added - 1 to indexing as because the loop starts at zero and index is actually 1 before:wq ans[size]
 x /= 10;} 			//I FORGOT TO /= 10 from x allowing next int to come in

	for(int i= 0 ; i<size;i++)
	{Inputs[i]=ans[i];}
	return Inputs;
  }






#include <stdio.h> //THIS IS JUST TO TEST THE FUNCTION TO SHOW IT WORKS AND WASNT REQUIRED
int main()
{
	int x = 1234;
	char Inputs[4];
	printf("%s", myitoa(x, Inputs));
}
