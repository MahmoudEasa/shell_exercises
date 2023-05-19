#include "main.h"

/**
 * exe - execute the program
 * @args: array of arguments
 * @env: array of environment variables
 */

void exe(char **args, char **env)
{
	char arg0[30] = "/bin/";

	if (*args[0] != '/' && (*args[0] != '.' && args[0][1] != '/'))
	{
		strcat(arg0, args[0]);
		if (execve(arg0, args, env) == -1)
			perror(args[0]);
	}
	else
		if (execve(args[0], args, env) == -1)
			perror(args[0]);
}

