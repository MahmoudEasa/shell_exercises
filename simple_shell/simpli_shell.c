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
	char *command = NULL;
	int len;

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
		run_fork(command, av, env);
	}
	return (0);
}
