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

void prompt(char **buf);
void exe(char **args, char **env);
char **split_str(char *str);
void _free(char **cmd);
void print_env(char **env);
char *allocate(char c, int size);

#endif /* #ifdef MAIN_H */

