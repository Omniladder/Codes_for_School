float centerX=800; 
float centerY=600; 
float radius;int 
charge;
PImage globe;
PImage globe2;
PImage globe3;
PImage globe0;
void setup()
{background(0);  
size(800, 600);  
centerX=width/2;  
centerY=height/2;  
radius=200;  
noStroke();  
globe = loadImage("Snow_Globe_Template_PNG_Clip_Art_Image.png"); 
globe2 = loadImage("Snow_Globe_Template_PNG_Clip_Art_Image.png"); 
globe3 = loadImage("Snow_Globe_Template_PNG_Clip_Art_Image.png"); 
globe0 = loadImage("Snow_Globe_Template_PNG_Clip_Art_Image.png");}
void draw(){charge(); 
globepic(); 
snowglobe(); 
globebase();
globeplate();
chargedisplay();
animate(charge);}
void snowglobe()
{fill(0, 191, 230, 100);
ellipse(centerX, centerY, radius*2, radius*2);
}
void chargedisplay()
{fill(255, 255, 255);
textSize(32); 
text (charge, centerX, centerY+radius+45);}
void globebase()
{fill(153, 77, 0); 
rect(centerX-radius, centerY+radius, radius*2, 75);}
void globeplate()
{fill(204, 170, 0);
rect(centerX-radius+15, centerY+radius+15,radius*2-30, 50);}
void globepic()
{globe0.resize (174, 200);
image (globe0, centerX-70, centerY+25); 
globe.resize (87, 100); 
image (globe, centerX-43, centerY+70); 
globe2.resize (44, 50); 
image (globe2, centerX-18, centerY+90); 
globe3.resize (22, 25); 
image (globe3, centerX-10, centerY+100);}
void charge()
{if (mousePressed==true&&mouseButton==LEFT)
{charge=charge+5;}  
if (mousePressed==true&&mouseButton==RIGHT)
{charge=0;}}
void animate(int c)
{while (c > 0)
{fill(255);
float x=0; 
float y=0; 
do {x=random(width); y=random(height);} 
while (dist(x,y,centerX,centerY) > radius);ellipse(x,y,5,5);c--;}}
