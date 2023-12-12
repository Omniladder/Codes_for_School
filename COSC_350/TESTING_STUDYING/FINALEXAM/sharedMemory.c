#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

struct sharedMemory{
	int dataArray[5];
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


void outputArray(struct sharedMemory memory)
{
	printf("[");
	for(int i = 0 ;  i < 5; i++)
	{
		printf("%d, ",memory.dataArray[i]);
	}
	printf("]\n");
}

int main()
{
	key_t shmKey, semKey;
	
	pid_t child;

	if((child = fork()) == -1)
	{
		perror("Failed to Fork the Child LOL");
		exit(-1);
	}

	int shmId, semId;
	if((shmKey = ftok(".", 'M')) == -1)
	{
		perror("Memory Key Failed");
		exit(-1);
	}

	if((semKey = ftok(".", 'S')) == -1)
	{
		perror("Semaphore Key Failed");
		exit(-1);
	}

	if((shmId = shmget(shmKey, sizeof(struct sharedMemory), 0666)) == -1)
	{
		perror("Failed to Open Memory");
		exit(-1);
	}

	if((semId = semget(semKey, 3, 0666)) == -1)
	{
		perror("Semaphore Failed to Open");
		exit(-1);
	}

	struct sharedMemory* memory = (struct sharedMemory*)shmat(shmId, NULL, 0);

	if(child == 0) //Child is Producer
	{
		while(1)
		{
			down(semId, 1); //Down the Empty
			down(semId, 0); //DOWN THE MUTEX

			memory->dataArray[semctl(semId, 2, GETVAL)] = rand() % 9 + 1;//Add an element to the Full slot 
			outputArray(*memory); //output the array
			printf("ADDED:: %d\n", memory->dataArray[semctl(semId, 2, GETVAL)]);
			up(semId, 2); //Up the Full
			up(semId, 0); //Up the Mutex
		
			sleep(1);
		}
	}
	else //Parent is the LEGENDARY CONSUMER BABBBBBYYYYYY!!!!
	{
		int removedData = 0;
		while(1)
		{
			down(semId, 2); //DOWN THE FULL
			down(semId, 0); //DOWN THAT FUCKING MUTEX BABY

			removedData = memory->dataArray[semctl(semId, 2, GETVAL)];
			memory->dataArray[semctl(semId, 2, GETVAL)] = 0; //SETS IT TO NOTHING
			outputArray(*memory); //output the array
			printf("REMOVED:: %d\n", removedData);

			up(semId, 1); //UP THIS SHIT EMPTY CAUSE WE ARE FURTHER AWAY FROM BEING EMPTY NOW
			up(semId, 0);//Up the Mutex so once again the code can run
			
			sleep(2);
		}
	}

}
