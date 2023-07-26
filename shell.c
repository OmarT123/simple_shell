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
		if (size_read == -1 && is_terminal)
		{
			_putchar('\n');
			break;
		}
		if (size_read == 1)
			continue;
		if (command[size_read - 1] == '\n')
			command[size_read - 1] = '\0';
		tokenize(command, args);
		check_ret = check(args[0], args);
		if (check_ret == 1)
			continue;
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
 * @command: input command
 * @args: array of argumens
 * Return: (1) if the command should be skipped,
 * (0) if the command is correct and should be executed
 * (-1) if an exit is read or an error and the program should stop
*/

int check(char *command, char *args[])
{
	char **env = environ;

	if (_strcmp(command, "exit") == 0)
	{
		handle_exit(args);
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

/**
 * handle_exit - handles when the command is an exit command
 * @args: input command and arguments
 * Return: 0 on success, -1 on failure
 */

int handle_exit(char *args[])
{
	int status = (args[1] == NULL) ? 0 : _atoi(args[1]);

	exit(status);
}
