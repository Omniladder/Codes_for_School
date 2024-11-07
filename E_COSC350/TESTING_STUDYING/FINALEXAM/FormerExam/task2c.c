#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

struct sharedMemory{
	int nums[2];
	int running;
}


int main()
{


}
