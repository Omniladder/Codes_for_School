//Dustin O'Brien
String [] q={"Batman","catwoman","joker","clayface","robin","red hood","mr.zsasz","red robin","NightWing","Talon","Court of Owls","Kite Man","Condiment King","Batwoman","Batgirl","Orphan","Riddler","Man-Bat","Penguin","Joe Chill","Ra's al Ghul","scarecrow","Hugo Strange","Alfred","Death Stroke","Calendar Man","Holiday","Ace The Bat-Hound","jim gordon","Mister Freeze","Harvey Bullock","Harley Quinn","Gaggy","Bane","Azrael","Poison Ivy","Deadshot","Firefly","Black Mask","hush"};
String textholder;
int timer=0;
int xPos;
int yPos;
void setup()
{size(600,600);
background(0);
textAlign(xPos+width/2,yPos+height/2);
textSize(20);
}
void draw()
{
frameRate(5);
xPos=int(random(0,600));
yPos=int(random(0,600));
  setRandomText();
  drawBubble(xPos,yPos);
  drawWord(xPos,yPos);
}
void setRandomText()
{
  textholder=q[(int) random(q.length)];
}
void drawBubble(float x, float y)
{
  stroke(0);
  fill(random(0,255),random(0,255),random(0,255));
  ellipse(x,y
}
