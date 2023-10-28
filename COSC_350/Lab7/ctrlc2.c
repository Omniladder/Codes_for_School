#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int timesTriggered = 0;

void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
    if(timesTriggered == 0)
    {timesTriggered++;}
    else
    {exit(0);}
}

int main()
{
struct sigaction act;
act.sa_handler = ouch;
sigemptyset(&act.sa_mask);
act.sa_flags = 0;
sigaction(SIGINT, &act, 0);
while(1) {
printf("Hello World!\n");
sleep(1);
}
}
