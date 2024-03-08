//Dustin O'Brien,Block 5 -Project Nightfall
void setup()
{
  size(500,500);
}
void draw()
{
  //Night Command Behind house
  if(mousePressed==true)
  {background(0);
  fill(193,193,193);
  ellipse(25,25,75,75);
  fill(0);
  ellipse(50,25,75,75);
}
  else
  {background(67,173,226);
fill(255,205,0);
  ellipse(25,25,75,75);
}
  //Garage house
  fill(193,52,16);
  rect(250,250,230,120);
  //Grass
  fill(39,191,34);
  rect(0,370,500,130);
  //Main House
  fill(193,52,16);
  rect(20,220,230,150);
  //Main Door
  fill(202,126,11);
  rect(135,270,50,75);
  //doorstep
  fill(135,135,135);
  rect(115,345,100,25);
  //garage roof
  triangle(250,250,250,220,480,250);
  //Main Roof
  triangle(20,220,135,120,250,220);
  //DoorKnob
  ellipse(175,310,10,10);
  //Garage Door
  fill(191,191,191);
  rect(300,300,130,70);
  //Walkway
  fill(191,191,191);
  rect(115,370,1000,50);
   //driveway
  fill(135,135,135);
  rect(250,370,400,1000);
   //Night Command Front of House
  if(mousePressed==true)
  {fill(232,226,55);
  rect(77.5,270,45,55);
}
  else
  {fill(104,241,255);
  rect(77.5,270,45,55);;
}
}
