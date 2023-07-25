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

/**
 * struct listnode - singly linked list
 * @num: number field
 * @str: string field
 * @next: pointer to next node
 */
typedef struct listnode
{
	int num;
	char *str;
	struct listnode *next;
} node;

int _execve(char *[]);
int buildargs(char *, char *[]);
int check(ssize_t, int, char *);
int getpath(char *[]);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
char *_strcpy(char *, char *);
char *_strchr(char *, char);
void tokenize(char *, char *[], int *);

#endif
