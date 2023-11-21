#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{

int data_processed;
int file_pipes[2]; int newPipe[2];
const char some_data[] = "123";
char buffer[BUFSIZ + 1];
pid_t fork_result;
memset(buffer, '\0', sizeof(buffer));

if (pipe(file_pipes) == 0 && pipe(newPipe) == 0) {
	
	fork_result = fork();

	if (fork_result == (pid_t)-1) {
		fprintf(stderr, "Fork failure");
		exit(EXIT_FAILURE);
	}

	if (fork_result == 0) {
		close(file_pipes[0]);
		close(newPipe[1]);
		sprintf(buffer, "%d", newPipe[0]);
		(void)execl("pipesChild", "pipesChild", buffer, file_pipes[1], newPipe[0]);
		exit(EXIT_FAILURE);
	}
	else {
		close(file_pipes[1]);
		close(newPipe[0]);
		data_processed = write(newPipe[1], some_data, strlen(some_data));
		printf("%d - wrote %d bytes\n", getpid(), data_processed);
		}
	}
exit(EXIT_SUCCESS);
}

