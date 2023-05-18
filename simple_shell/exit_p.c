#include "main.h"

/**
 * exit_p - exit the program
 * @command: array of arguments
 */

void exit_p(char **command)
{
	char *endptr;
	long int num;

	if (strcmp(command[0], "exit") == 0)
	{
		if (command[1])
		{
			num = strtol(command[1], &endptr, 10);
			_free(command);
			if (*endptr == '\0')
				exit(num);
			else
				exit(EXIT_SUCCESS);
		}
		else
		{
			_free(command);
			exit(EXIT_SUCCESS);
		}
	}
}

