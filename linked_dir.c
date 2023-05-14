#include "main.h"

/**
 * main - builds a linked list of the PATH directories
 *
 * Return: 0
 */

int main(void)
{
	char **paths, *path;
	Dir *head, *ptr;
	int len = 0;

	head = NULL;

	path = _getenv("PATH");
	paths = words(path, ":", &len);

	while (paths && *paths)
	{
		push(&head, *paths);
		if (!head)
			break;
		paths++;
	}

	ptr = head;
	if (ptr)
		while (ptr)
		{
			printf("%s\n", ptr->path);
			ptr = ptr->next;
		}

	_free(&head);
	return (0);
}

