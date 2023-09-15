int x;
int y;
int p;
void setup()
{size(600,600);
  background(0,0,155);}
void draw()
{
  background(155,155,255);


  fill(159,180,189);
  delay(50);
  y=100;
  ellipse(width/2,300,x,y);
  if(p==0)
  {
  x=x-9;
  }
  if(p==1)
  {
  x=x+9;
  }
  if(x<=5)
  {
    p=1;
  }
  if(x>=100)
  {
    p=0;
  }
}
