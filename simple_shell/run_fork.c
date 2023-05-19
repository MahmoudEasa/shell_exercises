#include "main.h"

/**
 * run_fork - run new program
 * @command: pointer to buffer
 * @av: array of arguments
 * @env: array of environment variables
 */

void run_fork(char **command, char **av, char **env)
{
	struct stat st;
	pid_t child;
	int status;
	char arg0[30] = "/bin/";

	exit_p(command);
	if (*command[0] != '/' && (*command[0] != '.' && command[0][1] != '/'))
		strcat(arg0, command[0]);
	else
		strcpy(arg0, command[0]);


	if (stat(arg0, &st) == 0)
	{
		child = fork();
		if (child == -1)
			perror("Error ");
		if (child == 0)
			exe(command, env);
		else
		{
			wait(&status);
			_free(command);
		}
	}
	else
	{
		_free(command);
		perror(av[0]);
	}
}

