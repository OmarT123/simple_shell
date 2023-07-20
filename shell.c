#include "shell.h"

/**
 * main - Entry point, the base of the shell
 * Return: Always 0
 */

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t size_read;
	char *args[2];
	int is_terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_terminal)
		{
			printf("$ ");
			fflush(stdout);
		}

		size_read = getline(&command, &bufsize, stdin);
		if (size_read == -1 && is_terminal)
		{
			printf("\n");
			break;
		}
		if (command[size_read - 1] == '\n')
			command[size_read - 1] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}
		if (strcmp(command, "") == 0)
			continue;
		args[0] = command;
		args[1] = NULL;
		_execve(args);
		if (!is_terminal)
			break;
	}
	return (0);
}
