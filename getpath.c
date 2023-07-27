#include "shell.h"

/**
 * find_path - finds path of command
 * @command: input command
 * Return: path of command
 */

char *find_path(char *command)
{
	char *dir, *path = _getenv("PATH"), *tokenize = _strdup(path);
	char command_path[MAX_COMMAND_LENGTH];
	size_t len;

	if (path != NULL)
	{
		dir = strtok(tokenize, ":");
		while (dir != NULL)
		{
			len = _strlen(dir) + _strlen(command);

			if (len <= MAX_COMMAND_LENGTH)
			{
				_strcpy(command_path, dir);
				_strcat(command_path, "/");
				_strcat(command_path, command);
			}
			if (access(command_path, X_OK) == 0)
				return (_strdup(command_path));
			dir = strtok(NULL, ":");
		}
	}
	return (NULL);
}

/**
 * _getenv - gets the environment variable value
 * @var: name of variable
 * Return: value of environment variable, NULL if not found
 */

char *_getenv(char *var)
{
	char **env = environ;
	char *variable;
	size_t i;

	for (; *env != NULL; ++env)
	{
		variable = *env;
		for (i = 0; var[i] != '\0' && variable[i] == var[i]; ++i)
		{
		}
		if (var[i] == '\0' && variable[i] == '=')
			return (variable + i + 1);
	}
	return (NULL);
}
