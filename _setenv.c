#include "main.h"

/**
 * main - changes or adds an environment variable
 * @name: string
 * @value: string
 * @overwrite: number
 *
 * Return: 0 on success -1 on error
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char *val;

	if (!name || !value)
		return (-1);

	if (overwrite)
	{
		val = _getenv(name);
		printf("\nPathe before if: %s\n", val);
		if (!val)
		{
			val = strdup(name);
			strcat(val, "=");
			strcat(val, value);
		}
		printf("\nPathe: %s\n", val);
	}

	return (0);
}

