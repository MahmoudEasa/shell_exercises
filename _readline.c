#include "main.h"

char* _readline(void)
{
	static char buffer[1024];
	int len;

	printf("$ ");
/*	r = read(STDIN_FILENO, buffer, 1024);*/

	if (fgets(buffer, 1024, stdin) == NULL)
	{
		printf("\n");
		return (NULL);
	}

	len = strlen(buffer) -1;

	if (buffer[len] == '\n')
		buffer[len] = '\0';

	if (feof(stdin))
	{
		printf("\n");
		return (NULL);
	}

	return (buffer);
}

