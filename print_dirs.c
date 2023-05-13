#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main(void)
{
	char *dir, **dirs;
	int dirs_len = 0;

	dir = _getenv("PATH");
	dirs = words(dir, ":", &dirs_len);
	printf("\nDir: %s\n", dir);

	while (dirs && *dirs)
	{
		printf("%s\n", *dirs);
		dirs++;
	}

	return (0);
}

