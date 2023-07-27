#include "shell.h"

/**
 * find_path - finds path of command
 * @command: input command
 * Return: path of command
 */

char *find_path(char *command)
{
	char copy[MAX_COMMAND_LENGTH];
	char *directory, *path = _getenv("PATH");
	char command_path[MAX_COMMAND_LENGTH];

	_strcpy(copy, path);
	directory = strtok(copy, ":");
	while (directory != NULL)
	{
		_strcpy(command_path, directory);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		if (access(command_path, F_OK) == 0)
			return (_strdup(command_path));
		directory = strtok(NULL, ":");
	}
	free(directory);
	free(path);
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
