#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void exe(char **arr);
void print_error();

/**
 * main -write a first version of a super simple shell
 *	that can run commands with their full path, without any argument.
 *
 * Return: 0
 */

int main(void)
{
	pid_t child;
	int status;
	char *exe1[] = {"/bin/ls", NULL};
	char *exe2[] = {"./ppid", NULL};
	char *exe3[] = {"^C", NULL};

	child = fork();
	if (child == -1)
		print_error();

	if (child == 0)
		exe(exe1);
	else
	{
		wait(&status);
		child = fork();
		if (child == -1)
			print_error();

		if (child == 0)
			exe(exe2);
		else
		{
			wait(&status);
			child = fork();
			if (child == -1)
				print_error();

			if (child == 0)
				exe(exe2);
			else
			{
				wait(&status);
				child = fork();
				if (child == -1)
					print_error();

				if (child == 0)
					exe(exe3);

			}
		}
	}

	return (0);
}

void print_error()
{
	perror("Error");
	exit (0);
}

void exe(char **arr)
{
	printf("\n#cisfun$ %s\n", arr[0]);
	execve(arr[0], arr, NULL);
}

