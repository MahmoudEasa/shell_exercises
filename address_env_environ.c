#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - prints the address of env and environ
 * @ac: number of arguments
 * @av: array of arguments
 * @env: environment
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	printf("Env Address: %p Environ Address: %p\n", (char *)env, (char *)environ);
	return (0);
}

