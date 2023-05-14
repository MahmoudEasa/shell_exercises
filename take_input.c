#include "main.h"

/**
 * takeInput - Function to take input
 *
 * Return: buffer or NULL
 */

char *takeInput()
{
	static char *buf;

	buf = _readline();
	if (strlen(buf) != 0)
		return (buf);

	return (NULL);
}

