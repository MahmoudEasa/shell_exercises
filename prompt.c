#include "main.h"

int prompt(void)
{
	static char buffer[1024];
	int r;

	printf("$ ");
/*	r = read(STDIN_FILENO, buffer, 1024);*/

	if (fgets(buffer, 1024, stdin) == NULL)
	{
		printf("\n");
		exit (EXIT_FAILURE);
	}

	r = strlen(buffer);

	if (feof(stdin))
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	printf("%s\n", buffer);
	return (r);
}

