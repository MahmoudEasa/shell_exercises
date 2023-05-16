#include "main.h"

/**
 * exe - execute the program
 * @args: array of arguments
 * @env: array of environment variables
 */

void exe(char **args, char **env)
{
	if (execve(args[0], args, env) == -1)
		perror(args[0]);
}

