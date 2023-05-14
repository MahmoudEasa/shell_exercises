#include "main.h"

/**
 * push - add new node in list
 * @head: pointer to first node
 * @str: string
 */

void push(Dir **head, char *str)
{
        Dir *new;

        new = malloc(sizeof(Dir));
        if (!new)
                return;

        new->path = strdup(str);
        new->next = *head;
        *head = new;
}

