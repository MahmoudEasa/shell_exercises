#include "main.h"

/**
 * allocate - allocate spase
 * @c: 'c' array of character 'p' array of pointer
 * @size: size of spase
 *
 * Return: pointer to new spase
 */ 

char *allocate(char c, int size)
{
	char *ptr;

	if (c == 'c')
		ptr = malloc(sizeof(char) * size);
	else
		ptr = malloc(sizeof(char *) * size);

	if (!ptr)
		exit (-1);

	return (ptr);
}

