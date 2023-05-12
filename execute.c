#include <stdio.h>
#include <unistd.h>
#include <sys/type.h>
#include <sys/wait.h>

/**
 * main - executes the command ls -l /tmp in 5 different child processes
 *
 * Return: 0
 */

int main(void)
{
	pid_t child;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp"};


}

