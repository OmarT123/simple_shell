#include "shell.h"

/**
 * buildargs - builds the array args
 * @command: the input command with its args
 * @args: the array to be built
 * Return: Always 0
 */

int buildargs(char *command, char *args[])
{
	int i = 0;
	char *token;

	token = strtok(command, " ");
	while (token != NULL && i < MAX_COMMAND_LENGTH - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (0);
}
