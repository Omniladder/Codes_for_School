float xpos;
float ypos;
float ccolor1;
float ccolor2;
float ccolor3;
void setup()
{
  background(0);
  size(500,500);
  xpos=random(100,400);
}
void draw()
{
  ccolor1= random(0,255);
  ccolor2= random(0,255);
  ccolor3= random(0,255);
  background(0);
  ypos=ypos+5;
  fill(139,69,19);
  rect(0,0,50,500);
  rect(450,0,50,500);
  fill(ccolor1,ccolor2,ccolor3);
  ellipse(xpos,ypos,50,50);
  if(ypos>550)
  {
    xpos=random(100,400);
    ypos=0;
  }}
