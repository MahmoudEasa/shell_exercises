#include "main.h"

int main()
{
	char *buffer;
	int r;

	while (1)
	{
		buffer = malloc(sizeof(char) * 1024);
		if (!buffer)
			exit(-1);

		r = read(STDIN_FILENO, buffer, 1024);

		if (r == 0)
			break;

		printf("len: %d buffer: %s\n", r, buffer);
		free(buffer);
	}

	return (0);
}

