void setup()
{
  size (500,500);
  background(0);
}

void draw()
{
  if (mousePressed==true && mouseButton==LEFT)
  {
    noStroke();
  fill (255,255,255);
  ellipse(mouseX,mouseY,20,20);
  }
  if (mousePressed==true && mouseButton==RIGHT)
  {
    fill (0);
  ellipse(mouseX,mouseY,50,50);
}
}
