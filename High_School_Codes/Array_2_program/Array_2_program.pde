int[]scores = {65, 46, 89, 22, 83, 43, 82, 65, 84, 45, 82, 99, 59, 35, 93,55, 45, 56, 22, 30, 99, 99, 99, 76, 91, 47, 27, 92, 72, 36, 68, 66, 25, 75,75, 40, 61, 5, 94, 53, 67, 79, 17, 95, 42, 83, 52, 97, 67, 88, 66, 31, 56,46, 47, 4, 16, 25, 63, 74, 82, 12, 52, 9, 91, 72, 92, 41, 94, 96, 90, 48,29, 34, 14, 84, 50, 76, 26, 16, 56, 71, 18, 50, 20, 10, 64, 54, 64, 99, 57,28, 18, 45, 28, 18, 28, 88, 94, 56, 96, 23, 91, 52};
int x;
int counter;
int counter2;
int total;
void setup()
{
  size(500,500);
background(0);
  sortscores();
  failscores();
  averagescore();
  allscores();
}
void sortscores()
{
  for (x=0;x<scores.length;x=x+1)
{
  if (scores[x] >= 90)
{counter=counter+1;}}
text(counter,250,100);
text("Scores that are A's",0,100);
}
void failscores()
{
  {
  for (x=0;x<scores.length;x=x+1)
{
  if (scores[x] <= 60)
{counter2=counter2+1;}}
text("failed scores",0,200);
text(counter2,250,200);
}}
void averagescore()
{
  for(x=1;x<scores.length;x=x+1)
  {total=total+scores[x];}
  total=total/scores.length;
  text("# of scores",0,300);
  text(scores.length,250,300);
}
void allscores()
{
    for(x=1;x<scores.length;x=x+1)
  {total=total+scores[x];}
  total=total/scores.length;
    text(total,250,400);
    text("Average scores",0,400);
}
