#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[]) 
{
	// Check if the correct number of command-line arguments is provided
	if (argc != 3) 
	{
		fprintf(stderr, "Usage: %s <pattern> <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	// Command to simulate 'grep'
	char command[100];
	snprintf(command, sizeof(command), "grep '%s' %s", argv[1], argv[2]);
	// Execute the command using system call
	int system_result = system(command);
	// Check the return value of the system call
	if (system_result == -1) 
	{
		perror("Error using system call");
		exit(EXIT_FAILURE);
	} 
	else if (WIFEXITED(system_result)) {
		// The child process terminated successfully
		int exit_status = WEXITSTATUS(system_result);
		if (exit_status == 0) {
			printf("Pattern found in the file.\n");
		} 
		else {	
			printf("Pattern not found in the file.\n");
		}
	} 
	else {
		printf("Child process did not terminate successfully.\n");
	}
	return 0;
}
