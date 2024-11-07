int xpos;
float sizes;
float ypos;
float[]speed = {1,2,3,4,5,};
void setup()
{
 size(600,600);
 background(101,216,239);
 
}
void draw()
{
  for(sizes=0;sizes<15;)
  for(xpos=0;xpos<600;xpos=xpos+6)
  {sizes=random(6,14);
  {if (ypos<0)
  {ypos=600+random(1,6);}
  xpos=xpos+speed.length;
  ellipse(xpos,600,sizes,sizes);}}}
