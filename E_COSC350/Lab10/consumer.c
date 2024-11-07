#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>



struct SharedMemory 
{
	int string[5];
	int count;
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

int main() {

	key_t key = ftok(".", -937700319);
	int memoryID = shmget(key, sizeof(struct SharedMemory), 0666);

	int dataSize = 5;
	

	struct SharedMemory *memory = (struct SharedMemory *)shmat(memoryID, (void *)0, 0);


	int consumedData;
	while (1) {

		while(memory->count <= 0) 
			sleep(1);
		consumedData = memory->string[memory->count - 1];
		memory->string[memory->count - 1] = 0;
		(memory->count) -= 1;

		printf("Consumed: %d\n", consumedData);

		outputMemory(memory);

		sleep(1);
	}

	shmdt(memory);

	return 0;
}
