import edu.cmu.ri.createlab.terk.robot.finch.Finch;
Finch myFinch = new Finch();
int speed;
int seconds;
int speed1;
int speed2;
void setup()
{
  speed1=235;
  speed2=235;
  seconds=1;
}
void draw()
{
  if(keyPressed==true&&key=='w')
  {driveForward();}
  if(keyPressed==true&&key=='s')
  {driveBackwards();}
  if(keyPressed==true&&key=='a')
  {turnLeft();}
  if(keyPressed==true&&key=='d')
  {turnRight();}
  if(keyPressed==true&&key=='q')
  {fastfwd();}
  if(keyPressed==true&&key=='x')
  {fastbck();}
}
void driveForward()
       {
         myFinch.setWheelVelocities(speed1, speed2, seconds * 100);
       }
void driveBackwards()
{
  myFinch.setWheelVelocities(-speed1, -speed2, seconds * 100);
}
void turnLeft()
{
  myFinch.setWheelVelocities(250,-250, seconds * 100);
}
void turnRight()
{
  myFinch.setWheelVelocities(-250,250, seconds * 100);
}
void fastfwd()
{myFinch.setWheelVelocities(255,255, seconds * 100);}
void fastbck()
{myFinch.setWheelVelocities(-255,-255, seconds * 100);}
