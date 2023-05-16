#include "main.h"

/**
 * run_fork - run new program
 * @command: pointer to buffer
 * @av: array of arguments
 * @env: array of environment variables
 */

void run_fork(char *command, char **av, char **env)
{
	struct stat st;
	pid_t child;
	char *args[2];
	int status;

	if (stat(command, &st) == 0)
	{
		child = fork();
		if (child == -1)
			perror("Error ");
		if (child == 0)
		{
			args[0] = command;
			args[1] = NULL;
			exe(args, env);
		}
		else
		{
			wait(&status);
			free(command);
		}
	}
	else
	{
		free(command);
		perror(av[0]);
	}
}

