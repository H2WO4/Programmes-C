/**
 * Author: Arthur Lamidel
 * 
 * Main function
 *  Handles the creation and destruction of the 2 child subprograms
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void randgen(int*);
void calculator(int*);

int main()
{
	// Initialize the pipe
	int* processPipe = (int*)malloc(2 * sizeof(int));
	pipe(processPipe);

	pid_t isParent;

	// Child 1
	// Random number generation
	isParent = fork();
	if (!isParent)
		randgen(processPipe);
	
	else if (isParent == -1)
	{
		perror("Could not fork properly");
		exit(1);
	}

	// Child 2
	// Calculating pi
	isParent = fork();
	if (!isParent)
		calculator(processPipe);
	
	else if (isParent == -1)
	{
		perror("Could not fork properly");
		exit(1);
	}

	// Wait for child 1
	if (wait(NULL) == -1)
	{
		perror("Could not find child");
		exit(2);
	}
	// Wait for child 2
	if (wait(NULL) == -1)
	{
		perror("Could not find child");
		exit(2);
	}

	exit(0);
}
