#include "main.h"

/**
 * main - fined a file in th PATH
 *
 * Return 0
 */

int main(int ac, char **av)
{
	char path[1024];
	struct stat st;
	int i;

	if (ac == 1)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	if (getcwd(path, sizeof(path)) == NULL)
	{
		perror("Error: ");
		return (1);
	}

	printf("\npath: %s\n", path);

	i = 1;
	while (av[i])
	{
		printf("%s ", av[i]);
		strcpy(path, av[i]);

		if (stat(path, &st) == 0)
			printf("FOUND\n");
		else
			printf("NOT FOUND\n");

		i++;
	}

	return (0);
}

