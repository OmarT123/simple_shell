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
	char *args[MAX_COMMAND_LENGTH];
	int is_terminal = isatty(STDIN_FILENO), check_ret, found;

	while (1)
	{
		if (is_terminal)
		{
			_putchar('$');
			_putchar(' ');
			fflush(stdout);
		}
		size_read = getline(&command, &bufsize, stdin);
		check_ret = check(size_read, is_terminal, command);
		if (check_ret == -1)
			break;
		else if (check_ret == 1)
			continue;
		tokenize(command, args);
		found = _strchr(args[0], '/') != NULL ? 0 : getpath(args);
		if (found == 0)
			_execve(args);
		if (!is_terminal)
			break;
	}
	return (0);
}

/**
 * check - checks some conditions to ensure the command given is correct
 * @size_read: size of input command
 * @is_terminal: indicates wether the program is running interactively
 * in terminal or not
 * @command: input command
 * Return: (1) if the command should be skipped,
 * (0) if the command is correct and should be executed
 * (-1) if an exit is read or an error and the program should stop
*/

int check(ssize_t size_read, int is_terminal, char *command)
{
	char **env = environ;

	if (size_read == -1 && is_terminal)
	{
		_putchar('\n');
		return (-1);
	}
	if (command[size_read - 1] == '\n')
		command[size_read - 1] = '\0';
	if (_strcmp(command, "exit") == 0)
	{
		free(command);
		return (-1);
	}
	if (_strcmp(command, "env") == 0)
	{
		while (*env)
		{
			_print_string(*env);
			env++;
		}
		return (1);
	}
	if (_strcmp(command, "") == 0)
		return (1);
	return (0);
}
