# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

int main(int argc, char* argv[])
{
	// * Check for args
	if (argc != 2)
	{
		perror("Invalid number of args");
		exit(1);
	}

	// * Open the file
	int f;
	if ((f = open(argv[1], O_RDONLY)) != -1)
	{
		// * Declare the result storage
		float avg[3] = {0, 0, 0};
		float min[3] = {__FLT_MAX__, __FLT_MAX__, __FLT_MAX__};
		float max[3] = {0, 0, 0};

		for (int j = 0; j < 3; j++)
		{
			// * Read the data
			float data[50];
			read(f, data, sizeof(float) * 50);
			for (int i = 0; i < 50; i++)
			{
				avg[j] += data[i];
				min[j] = fmin(min[j], data[i]);
				max[j] = fmax(max[j], data[i]);
			}
			avg[j] /= 50;
		}

		for (int j = 0; j < 3; j++)
			printf("AVG: %f; MIN: %f; MAX: %f\n", avg[j], min[j], max[j]);
	}
	// * Error handling
	else
	{
		perror("Unable to open the file");
		exit(2);
	}
}