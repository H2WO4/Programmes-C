# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>

long getDirSize(struct dirent* f)
{
	DIR* dd = opendir(f->d_name);
	chdir(f->d_name);

	long size = 0;

	struct dirent* ff;
	// Ignore '.' and '..'
	readdir(dd); readdir(dd);
	while ((ff = readdir(dd)) != NULL)
	{
		struct stat ffile;
		stat(ff->d_name, &ffile);
		if (S_ISDIR(ffile.st_mode))
		{
			size += getDirSize(ff);
		}
		
		size += ffile.st_size;
	}

	chdir("..");
	return size;
}

int main(int argc, char* argv[])
{
	// * Check for args
	if (argc != 2)
	{
		perror("Invalid number of args");
		exit(1);
	}

	DIR* d;
	// * Read the dir
	if ((d = opendir(argv[1])) != NULL)
	{
		chdir(argv[1]);

		struct dirent* f;
		// Ignore '.' and '..'
		readdir(d); readdir(d);
		// * Read the entries
		while ((f = readdir(d)) != NULL)
		{
			struct stat file;
			stat(f->d_name, &file);
			long size = 0;

			if (S_ISDIR(file.st_mode))
			{
				size += getDirSize(f);
			}
			size += file.st_size;

			printf("%-8ld: %s\n", size, f->d_name);
		}
		closedir(d);
	}
	// * Error handling
	else
	{
		perror("Unable to open the directory");
		exit(2);
	}

	return 0;
}