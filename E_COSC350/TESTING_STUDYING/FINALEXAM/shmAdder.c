#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct sharedMemory
{
	int num1, num2;
};

void down(int semid, int index) //Memorize this shit
{
struct sembuf buf = {index, -1, 0};
semop(semid, &buf, 1);
}

void up(int semid, int index) //Memorize this shit
{
struct sembuf buf = {index, 1, 0};
semop(semid, &buf, 1);
}

int main()
{
	pid_t child = fork();

	char buff[256];	
	
	key_t semaKey, memKey;
	int sema, memId; 

	if((semaKey = ftok(".", 'S')) == -1)
	{
		printf("Failed to Make Keys\n");
		exit(-1);
	}

	if((memKey = ftok(".", 'M')) == -1)
	{
		printf("Failed to make Memory Key");
	}
	
	if((memId = shmget(memKey, sizeof(struct sharedMemory), 0666)) == -1)
	{
		perror("Failed to get memory ID");
		exit(-1);
	}

	if((sema = semget(semaKey, 2, 0666)) == -1)
	{
		printf("FAILED to get Semaphore");
		exit(-1);
	}

	struct sharedMemory *memory = (struct sharedMemory *)shmat(memId, NULL, 0); //Needs to be a pointer Generally set second parameter to NULL generally you want it to be a pointer to whaere you want it and 0 is for flags like Read only so once again dont care

	if(child == 0)// child
	{
		while(1)
		{
			down(sema, 1); // down Set
			printf("Sum: %d\n", memory->num1 + memory->num2);
			up(sema, 0); //up not set
		}
	}
	else
	{
		while(fgets(buff, sizeof(buff), stdin) > 0)
		{
			down(sema, 0); // down not set
			if(sscanf(buff, "%d %d", &memory->num1, &memory->num2) != 2)//READ SHIT IN HERE
			{
				printf("INVALID Input\n");
				up(sema, 0); //Sets it back to use again
				continue;
			}
			up(sema, 1); //up Set
		}
		kill(child, SIGTERM);
	}
	exit(0);

}
