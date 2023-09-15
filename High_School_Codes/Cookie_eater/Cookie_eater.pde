PImage cookie;
int bites;
float x;
fl y;
float centerx;
float centery;
void setup()
{
  background(207,171,121);
  size(600,600);
  x=300;
  y=300;
  centerx=x/2;
  centery=y/2;
  cookie=loadImage ("cookie.png");
 cookie.resize(300,300);
  image(cookie, 150,150);
  text("Clicks: "+bites, 300,550);
}
void draw()
{
  
  background(207,171,121);
  cookie=loadImage ("cookie.png");
 cookie.resize(x,y);
  image(cookie, 150,150);
  text("Clicks: "+bites, 300,550);
  if(mousePressed==true&&mouseButton==LEFT)
  {
    bites=bites+1;
    x=random(0,10);
    x=random(0,10);
    
  }
if(mousePressed==true&&mouseButton==RIGHT)
  {
 bites=0;
  }
}
