#include "main.h"

/**
 * prompt - display a prompt and wait for the user to type a command
 * @buf: pointer to buffer
 */

void prompt(char **buf)
{
	printf("#cisfun$ ");
	if (fgets(*buf, 1024, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(*buf);
                        exit(EXIT_SUCCESS);
		}

		perror("Error ");
		*buf = NULL;
	}
}

