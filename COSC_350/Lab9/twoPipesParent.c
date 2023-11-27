#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

int data_processed;
int file_pipes[2]; int new_pipes[2];
const char some_data[] = "Hi there, Kiddo";
char buffer[BUFSIZ + 1];
char buffer2[BUFSIZ + 1];
pid_t fork_result;
memset(buffer, '\0', sizeof(buffer));

if (pipe(file_pipes) == 0 && pipe(new_pipes) == 0) {
	
	fork_result = fork();

	if (fork_result == (pid_t)-1) {
		fprintf(stderr, "Fork failure");
		exit(EXIT_FAILURE);
	}

	if (fork_result == 0) {
		close(file_pipes[0]);
		close(new_pipes[1]);
		sprintf(buffer, "%d", new_pipes[0]);
		sprintf(buffer2, "%d", file_pipes[1]);
		(void)execl("pipeChild", "pipeChild", buffer, buffer2, (char *)0);
		exit(EXIT_FAILURE);
	}
	else 
	{
		close(file_pipes[1]);
		close(new_pipes[0]);
		data_processed = write(new_pipes[1], some_data, strlen(some_data));
		printf("%d - wrote %d bytes\n", getpid(), data_processed);
		wait(NULL);
		while((data_processed = read(file_pipes[0], buffer, 256)) == 0) {;}
		printf("%d - read %d bytes %s\n", getpid(), data_processed, buffer);

	}
}
exit(EXIT_SUCCESS);
}
