#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int const READ_END = 0;
int const WRITE_END = 1;

int main()
{
int data_processed;
int file_pipes[2];
const char some_data[] = "123";
char* buffer;

buffer = (char *)calloc(strlen(some_data) + 1, sizeof(char));

strcpy(buffer, some_data);

buffer[strlen(some_data) + 1] = '\0';

if (pipe(file_pipes) == 0) {

	data_processed = write(file_pipes[WRITE_END], buffer, strlen(some_data));
	printf("Wrote %d bytes\n", data_processed);
	data_processed = read(file_pipes[READ_END], buffer, strlen(some_data));
	printf("Read %d bytes: %s\n", data_processed, buffer);

	exit(EXIT_SUCCESS);
}
exit(EXIT_FAILURE);
}
