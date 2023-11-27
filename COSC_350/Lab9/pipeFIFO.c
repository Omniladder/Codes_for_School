#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int const READ_END = 0;
int const WRITE_END = 1;

int main()
{
int data_processed;
int fileDescriptor;
const char some_data[] = "123";
char* buffer;

buffer = (char *)calloc(strlen(some_data) + 1, sizeof(char));

strcpy(buffer, some_data);

buffer[strlen(some_data) + 1] = '\0';

if ( (fileDescriptor = open("/tmp/task4_fifo", O_WRONLY)) > -1) {

	data_processed = write(fileDescriptor, buffer, strlen(some_data));
	printf("Wrote %d bytes\n", data_processed);
	data_processed = read(fileDescriptor, buffer, strlen(some_data));
	printf("Read %d bytes: %s\n", data_processed, buffer);

	exit(EXIT_SUCCESS);
}
exit(EXIT_FAILURE);
}
