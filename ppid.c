#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - print PPID
 *
 * Return: 0
 */

int main()
{
	printf("%u\n", getppid());
	return (0);
}

