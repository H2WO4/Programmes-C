/**
 * Author: Arthur Lamidel
 * 
 * Calculator function
 *  Receive input from the first subprogram
 *  Determine which pairs fall within the circle arc
 *  Calculate an approximation of pi based on the results
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void calculator(int* processPipe)
{
	int count = 0;
	double x, y;
	for (int i = 0; i < PRECISION; i++)
	{
		// Read both x and y from the pipe
		read(processPipe[0], &x, sizeof(double));
		read(processPipe[0], &y, sizeof(double));

		// If (x, y) is within the circle arc, count it
		if ((x*x + y*y) <= 1)
			count++;
	}

	// Calculate the approximation of pi
	double pi = 4. * count / PRECISION;
	printf("Pi is equal to approximatly %lf\n", pi);
	
	exit(0);
}
