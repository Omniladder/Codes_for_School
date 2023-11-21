#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t child1, child2;
	int pto1[2]; char buf[256];
	int C1to2[2]; int C2top[2]; int num;
	pipe(pto1);
	pipe(C1to2); pipe(C2top);
	if((child2 = fork())>0)
	{
		if((child1=fork())>0) //parent
		{
			while(read(0, buf, 256) == 0) {;}
			write(pto1[1], buf, 256); printf("parent sent %s to child 1\n", buf);
			while(read(C2top[0], buf, 256) == 0) {;}
			printf("parent received %s\n", buf); exit(0);}
		else //child 1
		{
			while(read(pto1[0], buf, 256)==0) {;}
			printf("child 1 %s from parent \n", buf);
			num = atoi(buf);
			num *=10; sprintf(buf, "%d", num);
			write(C1to2[1], buf, 256);
			printf("child 1 sent %s to child 2\n", buf);
			while(1) {;}
		}
	}
	else //child 2
	{
		while(read(C1to2[0], buf, 256) == 0){;}
		printf("child 2 received %s from child 1\n", buf); num = atoi(buf);
		num *= 100; sprintf(buf, "%d", num);
		write(C2top[1], buf, 256); printf("child 2 sent %s to parent\n", buf);
		while(1){;}
	}
	return 0;

}
