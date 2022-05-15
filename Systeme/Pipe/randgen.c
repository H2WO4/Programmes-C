/**
 * Author: Arthur Lamidel
 * 
 * Randgen function
 *  Handles the code of the first subprogram
 *  Generates 2*PRECISION numbers between 0-1
 *  Sends them through a pipe to the other subprogram
 */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "main.h"

void randgen(int* processPipe)
{
	// Initialize the RNG
	srand(time(NULL));

	double rnd;
	for (int i = 0; i < PRECISION; i++)
	{
		// Generate 2 doubles [0; 1[
		// And pipe them as soon as generated
		rnd = (double)rand() / (double)RAND_MAX;
		write(processPipe[1], &rnd, sizeof(double));

		rnd = (double)rand() / (double)RAND_MAX;
		write(processPipe[1], &rnd, sizeof(double));
	}
	
	exit(0);
}
