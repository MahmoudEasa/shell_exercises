#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void exe(char **argv);

/**
 * main - executes the command ls -l /tmp in 5 different child processes
 *
 * Return: 0
 */

int main(void)
{
	pid_t child, child_pid, parent;
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	(void)i;
	for (i = 0; i < 5; i++)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error");
			return (1);
		}

		if (child == 0)
		{
			child_pid = getpid();
			parent = getppid();
			printf("\n--- child PID: %u parent: %u ---\n", child_pid, parent);
			exe(argv);
		}
		else
			wait(&status);
	}

	return (0);
}

void exe(char **argv)
{
	int status;

	status = execve(argv[0], argv, NULL);
	if (status == -1)
		perror("Error");
}

