#include "main.h"

/**
 * free - free a node
 * @head: pointer to first node
 */

void _free(Dir **head)
{
	Dir *ptr;

	if (!head)
		return;

	while (*head)
	{
		ptr = (*head)->next;
		free((*head)->path);
		free(*head);
		*head = ptr;
	}
}

