#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;

int _putchar(char);
int _print_string(char *s);
int _execve(char *[]);
int buildargs(char *, char *[]);
int check(char *, char *[]);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
char *_strcpy(char *, char *);
char *_strchr(char *, char);
void tokenize(char *, char *[]);
int handle_exit(char *[]);
int _atoi(char *);
int is_empty(char *, char *[]);
char *find_path(char *);
char *_getenv(char *);

#endif

