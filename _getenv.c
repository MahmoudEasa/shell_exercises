#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * _getenv - gets an environment variable
 * @name: environment name
 *
 * Return: pointer to value of environment name
 */

char *_getenv(const char *name)
{
	int i, j;
	char **envp = environ;
	char *val = NULL;

	if (!name)
		return (0);

	j = 0;
	for (i = 0; i < strlen(name); i++)
	{
		while (envp[j])
		{
			if (name[i] == envp[j][i] && envp[j][i + 1] != '=')
				break;
			else if (name[i] == envp[j][i] && envp[j][i + 1] == '=')
			{
				val = &envp[j][i + 2];
				break;
			}
			j++;
		}
	}
	return (val);
}

