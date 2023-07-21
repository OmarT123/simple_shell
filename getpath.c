#include "shell.h"

/**
 * getpath - gets the path of the command
 * @args: array of arguments
 * Return: (0) if found, (-1) if not found
 */

int getpath(char *args[])
{
	char *path = getenv("PATH"), *tokenize = strdup(path);
	char *dir;
	char command_path[MAX_COMMAND_LENGTH];
	size_t path_length;

	if (path != NULL)
	{
		dir = strtok(tokenize, ":");
		while (dir != NULL)
		{
			path_length = strlen(dir) + strlen(args[0]) + 2;
			memset(command_path, '\0', sizeof(command_path));
			if (path_length <= MAX_COMMAND_LENGTH)
			{
				strcpy(command_path, dir);
				strcat(command_path, "/");
				strcat(command_path, args[0]);
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
