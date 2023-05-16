#include "main.h"

/**
 * main - simpli shell
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of environmen variables
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char *command = NULL, *args[2];
	struct stat st;
	pid_t child;
	int status, len;

	(void)ac;
	while (1)
	{
		command = allocate('c', 1024);
		prompt(&command);
		len = strlen(command);
		if (*command == '\n')
		{
			free(command);
			continue;
		}
		command[len - 1] = '\0';
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
	return (0);
}
