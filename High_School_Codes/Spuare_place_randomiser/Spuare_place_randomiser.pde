void setup()
{
  size(500,500);
  background(0);
 
 
}
void draw()
{
if(mousePressed==true)
{
  background(0);
   for(int i=1;i<11; i=i+1)
  {
    fill(255,255,0);
    rect(random(0,500),random(0,500),100,100);
  }
}
}
