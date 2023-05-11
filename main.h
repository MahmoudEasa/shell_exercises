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

char **words(char *str, char *tok, int *arr_len);
char *_strtok(char *str, char *tok);
char *allocate(char *token, char tok, int *tok_len);

#endif /* #ifdef MAIN_H */
