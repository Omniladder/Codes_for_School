void setup()
{
  //sky
  size(500,500);
  background(51,51,225);
  //grass
  fill(25,225,25);
  rect(0,400,500,100);
   //trunk
  fill(139,69,19);
  rect(225,250,50,150);
}
void draw()
{
   //erase
  if (mousePressed==true&&mouseButton==RIGHT&&mouseX>100&&mouseY>100&&mouseX<400&&mouseY<333)
  {
    noStroke();
    fill(51,51,225);
    ellipse(mouseX,mouseY,25,25);
  }
  //leaves
  if (mousePressed==true&&mouseButton==LEFT&&mouseX>100&&mouseY>100&&mouseX<400&&mouseY<333)
  {
    fill(0,random(0,255),0);
    noStroke();
    ellipse(mouseX+random(-30,30),mouseY+random(-30,30),random(12,18),random(12,18));
  }

  }
  
