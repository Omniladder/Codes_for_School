float i;
int q;
int p;
float px;
float py;
float randomiser1;
float randomiser2;
int score;
void setup ()
{size (800,800);
background (0);
i=300;
randomiser1=20;
randomiser2=20;
py=20;
px=20;
score=0;
}
 void draw ()
{px=randomiser1+px;
py=randomiser2+py;
  fill (255,255, 255);
  background  (0);
    if (mouseY>i&&i<650)
    {i=i+13;}
    if (mouseY<i&&i>150)
    {i=i-13;}
  ellipse(px,py,30,30);
  rect (700,i-150,100,300);
if (px<0)
{randomiser1=-randomiser1;}
//if (px>800)
//{randomiser1=randomiser1*-1;}
if (py>0)
{randomiser2=randomiser2*-1;}
if (py<800)
{randomiser2=randomiser2*-1;}
if (px ==700&&i-125<=py&&py<i+300)
{randomiser1=randomiser1*-1;
score=score+1;}
if (px>900)
{death ();}}
void death()
{background(0);
fill (255);
rect(100,200,600,400);
fill (0);
textSize (100);
text ("score: "+score,250,300);
fill (255,0,0);
rect (250,720,500,100);
fill (255);
text ("restart",350,750);
if (mousePressed)
{
if(mouseX >250&&mouseX<750&&mouseY >720&&mouseY<820)
{setup ();}}
}
