#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

void down(int semid, int index)
{
struct sembuf buf = {index, -1, 0};
semop(semid, &buf, 1);
}

void up(int semid, int index)
{
struct sembuf buf = {index, 1, 0};
semop(semid, &buf, 1);
}


struct SharedMemory
{
	int string[5];
};

void outputMemory(struct SharedMemory*  memory)
{
	printf("[");
	for(int i = 0; i < 5; i++)
	{
		printf(", %d", memory->string[i]);
	}
	printf("]\n");
}
int main()
{

        int dataSize = 5;    
            
        int Mutex = 0 , Full = 1, Empty = 2;    
    
        key_t mutexKey, memoryKey;    
        int mutexId, shMemId;    
    
            
    
        if ((mutexKey = ftok(".", 'M')) == -1 || (memoryKey = ftok(".", 'S')) == -1)    
        {    
                perror("ftok Error");    
                exit(1);    
        }    
            
        if ((mutexId = semget(mutexKey, 3, 0666)) == -1 || (shMemId = shmget(memoryKey, sizeof(struct SharedMemory), 0666)) == -1)                                                                                                                              
        {                                                                                                                       
                perror("semget Error");    
                exit(1);    
        }    
             
    
        int consumedData;                           
    
    
        struct SharedMemory *memory = (struct SharedMemory *)shmat(shMemId, (void *)0, 0);   

	while(1)
	{

		down(mutexId, Full);
		down(mutexId, Mutex);

		consumedData = memory->string[semctl(mutexId, Full, GETVAL)];

		memory->string[semctl(mutexId, Full, GETVAL)] = 0;

		outputMemory(memory);

		printf("CONSUMER REMOVED :: %d\n", consumedData);

		up(mutexId, Mutex);
		up(mutexId, Empty);

		
		sleep(1);
	}
	
}
