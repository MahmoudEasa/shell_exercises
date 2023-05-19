#include "main.h"

/**
 * exit_p - exit the program
 * @command: array of arguments
 */

void exit_p(char **command)
{
	int num;

	if (strcmp(command[0], "exit") == 0)
	{
		if (command[1])
		{
			num = atoi(command[1]);
			_free(command);
			if (num != 0)
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

