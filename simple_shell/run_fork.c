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

	handle_command(command, &arg0);
	if (strcmp(arg0, "/bin/exit") == 0)
		exit_p(command);

	if (stat(arg0, &st) == 0)
	{
		child = fork();
		if (child == -1)
			perror("Error ");
		if (child == 0)
		{
			if (strcmp(arg0, "/bin/echo") == 0 && command[1])
				check_command(command, child);
			else if (strcmp(arg0, "/bin/echo") == 0)
				exit(EXIT_SUCCESS);
			exe(command, env);
		}
		else
		{
			wait(&status);
			if (command[1])
				if (strcmp(arg0, "/bin/echo") == 0
					&& strcmp(command[1], "$$") == 0)
					printf("%u\n", child);
			_free(command);
		}
	}
	else
	{
		_free(command);
		perror(av[0]);
	}
}

/**
 * check_command - check echo $
 * @command: array of arguments
 * @child: PID or PPID
 */

void check_command(char **command, pid_t child)
{
	int len, i;

	if (strcmp(command[1], "$?") == 0)
	{
		printf("%u\n", child);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(command[1], "$$") == 0)
		exit(EXIT_SUCCESS);
	else if (command[1][0] == '$')
	{
		len = strlen(command[1]);
		for (i = 0; i <= len; i++)
			command[1][i] = command[1][i + 1];

		printf("%s\n", getenv(command[1]));
		exit(EXIT_SUCCESS);
	}
}

/**
 * handle_command - Handle The Path of command
 * @command: array of arguments
 * @arg0: array of "/bin/"
 */

void handle_command(char **command, char (*arg0)[30])
{
	if (*command[0] != '/' && (*command[0] != '.' && command[0][1] != '/'))
		strcat(*arg0, command[0]);
	else
		strcpy(*arg0, command[0]);
}

