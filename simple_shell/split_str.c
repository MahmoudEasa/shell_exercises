#include "main.h"

/**
 * split_str - split string
 * @str: string
 *
 * Return: pointer to array of string
 */

char **split_str(char *str)
{
	char **command = NULL, *arg, *strp = strdup(str);
	int len, i;

	arg = strtok(strp, " ");
	if (arg != NULL)
		len = 1;
	while ((arg = strtok(NULL, " ")) != NULL)
		len++;
	free(strp);

	arg = strtok(str, " ");
	if (arg)
	{
		command = malloc(sizeof(char *) * (len + 1));
		if (!command)
			exit(-1);
		i = 0;
		while (arg)
		{
			len = strlen(arg);
			command[i] = malloc(sizeof(char) * len);
				if (!command[i])
				{
					_free(command);
					exit(-1);
				}
			strcpy(command[i], arg);
			i++;
			arg = strtok(NULL, " ");
		}
		command[i] = NULL;
	}
	return (command);
}

