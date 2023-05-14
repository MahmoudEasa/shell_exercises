#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

typedef struct dir
{
	char *path;
	struct dir *next;
} Dir;

char **words(char *str, char *tok, int *arr_len);
char *_strtok(char *str, char *tok);
char *allocate(char *token, char tok, int *tok_len);
char *_getenv(const char *name);
void push(Dir **head, char *str);
void _free(Dir **head);

#endif /* #ifdef MAIN_H */
