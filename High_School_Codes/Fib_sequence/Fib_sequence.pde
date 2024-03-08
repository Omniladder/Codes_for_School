//Dustin O'Brien
int x1=0;
int x2 =1;
int p =0;
int n;
void setup()
{for (n=0; n<10000; n=n+x1)
{print(x1+", ");
x1=p+x2;
x2=p;
p=x1;}}
