#include "shell.h"

/**
 * getpath - gets the path of the command
 * @args: array of arguments
 * Return: (0) if found, (-1) if not found
 */

int getpath(char *args[])
{
	char *path = getenv("PATH"), *tokenize = _strdup(path);
	char *dir;
	char command_path[MAX_COMMAND_LENGTH];
	size_t path_length;

	if (path != NULL)
	{
		dir = strtok(tokenize, ":");
		while (dir != NULL)
		{
			path_length = _strlen(dir) + _strlen(args[0]) + 2;
			if (path_length <= MAX_COMMAND_LENGTH)
			{
				_strcpy(command_path, dir);
				_strcat(command_path, "/");
				_strcat(command_path, args[0]);
				if (access(command_path, X_OK) == 0)
				{
					args[0] = command_path;
					return (0);
				}
			}
			dir = strtok(NULL, ":");
		}
	}
	return (-1);
}
