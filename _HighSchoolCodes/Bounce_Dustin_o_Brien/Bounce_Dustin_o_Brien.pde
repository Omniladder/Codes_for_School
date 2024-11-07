//Dustin O'Brien Block one 
float xPos;
float yPos;
int bSize;
float xSpeed;
float ySpeed;
void setup()
{
    bSize=100;
  size(500,500);
  xSpeed=random(-2,2);
   ySpeed=random(-2,2);
  xPos=width/2;
  yPos=height/2;
  background(0);
}
void draw()
{
  background(0);
  xPos=xPos+xSpeed;
  fill(255,255,255);
  ellipse(xPos,yPos,bSize,bSize);
    yPos=yPos+ySpeed;
    if (xPos>500)
    {
      xSpeed=xSpeed*-1;
    }
     if (yPos>500)
    {
      ySpeed=ySpeed*-1;
    }
     if (xPos<0)
    {
      xSpeed=xSpeed*-1;
    }
      if (yPos<0)
    {
      ySpeed=ySpeed*-1;
    }
}
