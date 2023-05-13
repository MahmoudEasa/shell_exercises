#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	char **envp = environ;
	int i;

	i = 1;
	while (*envp)
	{
		printf("Env[%d]: %s\n", i, *envp);
		i++;
		envp++;
	}

	return (0);
}

