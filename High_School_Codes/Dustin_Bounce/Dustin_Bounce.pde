//Dustin O’Brien Block 5 Bounce Ball
float xPos;
float yPos;
int bSize;
float xSpeed;
float ySpeed;
void setup()
{
  size(500,500);
  background(0);
  yPos=250;
  xPos=250;
  xSpeed=random(-2,2);
  ySpeed=random(-2,2);
}
void draw()
{
  background(0);
  bSize=100;
  xPos=xPos+xSpeed;
  yPos=yPos+ySpeed;
  fill(255,255,255);
  ellipse(xPos,yPos,bSize,bSize);
  if (xPos>450)
  {
  xSpeed=xSpeed*-1;
  }
  if (yPos>450)
  {
  ySpeed=ySpeed*-1;
  }
   if (yPos<50)
  {
  ySpeed=ySpeed*-1;
  }
   if (xPos<50)
  {
  xSpeed=xSpeed*-1;
  }
}
