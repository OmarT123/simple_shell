#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;

int _execve(char *[]);
int buildargs(char *, char *[]);

#endif
