#include "shell.h"

/**
 * main - Entry point, the base of the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *command = NULL, *found = NULL;
	size_t bufsize = 0;
	ssize_t size_read;
	char *args[MAX_COMMAND_LENGTH];
	int is_terminal = isatty(STDIN_FILENO), check_ret, x = argc;

	while (1 && x == argc)
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
		if (is_empty(command, argv) == 1)
			continue;
		if (_strlen(command) == 1)
			continue;
		if (command[size_read - 1] == '\n')
			command[size_read - 1] = '\0';
		tokenize(command, args);
		check_ret = check(args[0], args);
		if (check_ret == 1)
			continue;
		found = (_strchr(args[0], '/') != NULL) ? NULL : find_path(args[0]);
		if (found != NULL)
			args[0] = found;
		_execve(args);
		free(found);
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

/**
 * is_empty - checks if input string is empty or not
 * @s: input string
 * @argv: array of arguments
 * Return: 1 if empty, 0 if not empty
 */

int is_empty(char *s, char *argv[])
{
	char *temp = s, *t;
	int con = 0;

	while (*temp)
	{
		if (*s != '\033')
			return (0);
		s++;
		con = *(s + 1) == 'A' || *(s + 1) == 'B' ? 1 : 0;
		if (*s == '[' && (con || *(s + 1) == 'C' || *(s + 1) == 'D'))
		{
			t = argv[0];
			_strcat(t, ": No such file or directory");
			_print_string(t);
			return (1);
		}
		temp++;
	}
	return (0);
}

