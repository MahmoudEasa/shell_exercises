#include "main.h"

/**
 * exe - execute the program
 * @args: array of arguments
 * @env: array of environment variables
 */

void exe(char **args, char **env)
{
	char arg0[30] = "/bin/";

	handle_command(args, &arg0);

	if (strcmp(arg0, "/bin/echo") == 0 && !args[1])
		return;

	if (execve(arg0, args, env) == -1)
		perror(args[0]);
}

