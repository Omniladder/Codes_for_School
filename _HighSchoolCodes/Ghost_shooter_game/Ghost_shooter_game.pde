float xPos;
float yPos;
int Ccolor;
float EyPos;
float ExPos;
int time;
float randomiser;
float randomiser2;
float btime;
float bmovement;
float cloaktime;
float Ntime;
int i;
int p;
float ghosttime;
float Ncolor;
void setup()
{
  Ncolor=0;
  background(0);
  size(500,500);
  time=millis();
  randomiser2=random(500,100);
  randomiser=random(1000,4000);
  Ccolor=255;
  EyPos=400;
  btime=millis();
  ExPos=500;
  ExPos=bmovement;
  cloaktime=millis();
  i=1;
  yPos=0;
  xPos=0;
    fill(0,76,175);
  rect(400,EyPos,100,100);
  p=0;
}
void draw()
{
  background(0);
      fill(255,0,0);
  rect(ExPos,EyPos+45,500,10);
  bmovement=bmovement-1;
  fill(Ccolor,Ccolor,Ccolor);
  rect(xPos,yPos,100,100);
  if(keyPressed==true&&key=='d')
  {
    xPos=xPos+5;
  }
    if(keyPressed==true&&key=='a')
  {
    xPos=xPos-5;
  }
   if(keyPressed==true&&key=='w')
  {
    yPos=yPos-5;
  }
   if(keyPressed==true&&key=='s')
  {
    yPos=yPos+5;
  }
  if(keyPressed==true&&key=='q')
  {
    Ccolor=0;
  i=0;
  }
  Enemy();
  death();
  deathNotice();
  if(keyPressed==true&&key=='e')
  {
    Ccolor=255;
    i=1;
  }
}


void Enemy()
{
    //enemy move code
if(millis()>time+randomiser)
{
  time=millis();
  background(0);
  randomiser=random(100,4000);
  EyPos=yPos;
}
  //Bullets
  fill(255,0,0);
  rect(ExPos,EyPos+45,500,10);
   fill(0,76,175);
  rect(400,EyPos,100,100);
}
void death()
{if(i>=1)
  {if ((yPos<EyPos) || (yPos>EyPos))
{}
else
{ p=1;}
}
if(p>=1)
{
  background(255,0,0);
}}
void deathNotice()
{
  if(millis()>randomiser2-Ntime)
  {
    fill(Ncolor);
    rect(0,0,10,10);
    Ntime=millis();
    randomiser2=random(500,100);
    Ncolor=255;
  }
  else
  {
    Ncolor=0;
  }
}
