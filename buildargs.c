#include "shell.h"

/**
 * tokenize - tokenizes the command into its name and arguments
 * @command: input command
 * @args: array of arguments
 */

void tokenize(char *command, char *args[])
{
	int i = 0, j, len = _strlen(command), start = -1;

	for (j = 0; j < len; j++)
	{
		if (command[j] == '#')
			break;
		else if (command[j] == ' ' || command[j] == '\t' || command[j] == '\n')
		{
			if (start != -1)
			{
				command[j] = '\0';
				args[i++] = &command[start];
				start = -1;
			}
		}
		else if (start == -1)
			start = j;
	}
	if (start != -1)
	{
		command[len] = '\0';
		args[i++] = &command[start];
	}
	args[i] = NULL;
}
