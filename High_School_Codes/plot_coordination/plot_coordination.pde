//Dustin T. O'Brien Block 5 2018 Plot Coordination Project
int p;
float tickx;
float ticky;
float x1;
float x2;
float y1;
float y2;
float midpointx;
float midpointy;
float slope;
float distance;
PFont font;
void setup()
{
  size(600,600);
  p=0;
  if(p<=1)
  {
  x1=4;
  x2=-4;
  y2=-2;
  y1=5;
  }
  
}
void distance()
{
  distance=sqrt(sq(x2-x1)+sq(y2-y1));
  text("distance= "+distance,30,590);
}
void slope()
{
  slope=(y2-y1)/(x2-x1);
  text("slope = "+slope,350,590);
}
void graph()
{
  delay(100);
  background(0);
  strokeWeight(.1);
  for(tickx=0;tickx<600;tickx=tickx+30)
  {line(tickx,0,tickx,600);}
  for(ticky=0;ticky<600;ticky=ticky+30)
  {line(0,ticky,600,ticky);}
  strokeWeight(1);
  stroke(155,0,0);
  line(300,0,300,600);
  line(0,300,600,300);
  stroke(255);
}
void coordinates()
{
  
  line(x1*30+300,-y1*30+300,x2*30+300,-y2*30+300);
  ellipse(x1*30+300,-y1*30+300,5,5);
  text(x1+", "+y1,x1*30+310,-y1*30+300);
  ellipse(x2*30+300,-y2*30+300,5,5);
  text(x2+", "+y2,x2*30+310,-y2*30+300);
  text("Known Coordinates:",30,10);
  text("Coordinate 1: "+ x1+","+y1,30,40);
  text("Coordinate 2: "+ x2+","+y2,30,70);
}
void midpoint()
{
  midpointx=(x1+x2)/2;
  midpointy=(y1+y2)/2;
  ellipse(midpointx*30+300,-midpointy*30+300,10,10);
  noFill();
  ellipse(midpointx*30+300,-midpointy*30+300,15,15);
  ellipse(midpointx*30+300,-midpointy*30+300,20,20);
  fill(255);
  text("Midpoint: "+midpointx+"," +""+midpointy,310,15);
  text("Midpoint: "+midpointx+"," +""+midpointy,midpointx*30+310,-midpointy*30+290);
}
void draw()
{
  font=createFont("consolas",15);
  textFont(font);
  if(keyPressed&&key=='e')
  {
    p=0;
  }
  if(keyPressed&&key=='q')
  {
    p=2;
  }
  if(p>=0&&keyPressed&&key=='d'&&p<=0)
  {
    x1=x1+1;
  }
  if(p>=0&&keyPressed&&key=='a'&&p<=0)
  {
    x1=x1-1;
  }
  if(p>=0&&keyPressed&&key=='s'&&p<=0)
  {
    y1=y1-1;
  }
  if(p>=0&&keyPressed&&key=='w'&&p<=0)
  {
    y1=y1+1;
  }
  if(p>=2&&keyPressed&&key=='d'&&p<=2)
  {
    x2=x2+1;
  }
  if(p>=2&&keyPressed&&key=='a'&&p<=2)
  {
    x2=x2-1;
  }
  if(p>=2&&keyPressed&&key=='s'&&p<=2)
  {
    y2=y2-1;
  }
  if(p>=2&&keyPressed&&key=='w'&&p<=2)
  {
    y2=y2+1;
  }
  stroke(255);
  graph();
  coordinates();
  midpoint();
  slope();
  distance();
}
