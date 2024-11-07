// INITIALIZE THE ARRAY WITH A DATASET OF 100+ RANDOM SCORES 0-100
int[]scores = {52,69,85,98,95,76,82,83,92,87,94,68,77,45,70,71,59,60,74,84};
float total =0; // Used to total all scores
float avgscore =0; // Used to calculate average score
int counter =0; 
int counter2 =0; 
int x;
int y;
int z;
int TotalA;
int TotalB;
int TotalC;
int TotalD;
int TotalF;
float variance;
float totalDif;
float Deviation;
int text;
PFont font;
float c1;
float c2;
void setup()  // SET UP DRAWING SCREEN
{
size(600, 500); // SET CANVAS SIZE TO 600 x 500
background(0); // SET BACKGROUND COLOR TO BLACK
font();
sortscores(); // Call the method sortscores
High(); // Call the method Highscores
averagescore(); // Call the method averagescore
scores();
TotalA();
TotalB();
TotalC();
TotalD();
TotalF();
Bars();
variance();
}
void scores()
{textFont(font);
  text("Number of scores:",63,50);
  text(scores.length,248,50);
}
  void sortscores()
  {textFont(font);
    for(x=0;x<scores.length;x=x+1)
    {
if (scores[x] < scores[y])
{counter=scores[x];}}
text(counter,248,70);
text("Low Score:",140,70);
}
  
  void High()
  {
    for(x=0;x<scores.length;x=x+1)
{
if (scores[x] > counter)
 {counter=scores[x];}}
 text(counter,248,90);
 text("High Score:",130,90);
  }
  void averagescore()
  {
     for(x=0;x<scores.length;x=x+1)
     {total=total+scores[x];}
     total=total/scores.length;
     text(total,240,110);
     text("Average exam score:",43,110);
  }
 void TotalA()
  {textFont(font);
   for(x=0;x<scores.length;x=x+1)
    {
if (scores[x] >= 90)
{TotalA=TotalA+1;}}
text(TotalA,290,200);
text("Total A's:",180,200);
}  
void TotalB()
{
   for(x=0;x<scores.length;x=x+1)
    {
if (scores[x]>=80 && scores[x]<90)
{TotalB=TotalB+1;}
}
text(TotalB,290,220);
text("Total B's:",180,220);
}
void TotalC()
{for(x=0;x<scores.length;x=x+1)
    {
if (scores[x]>=70 && scores[x]<80)
{TotalC=TotalC+1;}
}
text(TotalC,290,240);
text("Total C's:",180,240);}
void TotalD()
{for(x=0;x<scores.length;x=x+1)
    {
if (scores[x]>=65 && scores[x]<70)
{TotalD=TotalD+1;}
}
text(TotalD,290,260);
text("Total D's:",180,260);}
void TotalF()
{for(x=0;x<scores.length;x=x+1)
    {
if (scores[x]<65)
{TotalF=TotalF+1;}
}
text(TotalF,290,280);
text("Total F's:",180,280);}
  void Bars()
  {fill(255);
  
    rect(320,190,TotalA*40,10);
    rect(320,210,TotalB*40,10);
    rect(320,230,TotalC*40,10);
    rect(320,250,TotalD*40,10);
    rect(320,270,TotalF*40,10);
  
{fill(175);}
  {
    rect(TotalA*40+320,190,10,10);
    rect(TotalB*40+320,210,10,10);
    rect(TotalC*40+320,230,10,10);
    rect(TotalD*40+320,250,10,10);
    rect(TotalF*40+320,270,10,10);
  }}
  void variance()
  {
    for (z=0;z<scores.length;z=z+1)
    {
      c1=scores[z]-avgscore;
      c2=sq(c1);
      totalDif=totalDif+c2;
      variance=totalDif/scores.length;
      Deviation=sqrt(variance);
      println(Deviation);
    }
      fill(255);
      textFont(font);
      text(Deviation,240,130);
      text("Standard Deviation:",43,130);
  }
 void font()
 {
   font=createFont("consolas",20);
 }
