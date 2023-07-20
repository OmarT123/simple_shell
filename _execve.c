#include "shell.h"

/**
 * _execve - executes a given command
 * @args: array of arguments
 * Return: Always 0
 */

int _execve(char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fail");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	return (0);
}
