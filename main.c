#include "main.h"

/**
 * main - Entry point, Reads command from user
 * and executes it until end of file
 * Return: Always 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *fullCommand[2];
	ssize_t length;

	while (1)
	{
		printf("#Shell$ ");
		fflush(stdout);
		length = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
		if (length == -1)
		{
			perror("read");
			continue;
		}
		else if (length == 0)
		{
			printf("\n");
			break;
		}
		else
		{
			command[length - 1] = '\0';
			fullCommand[0] = command;
			fullCommand[1] = NULL;
			execute(command, fullCommand);
		}
	}
	return (0);
}

/**
 * execute - takes a command and its arguments and executes it
 * @command: name of command
 * @fullCommand: command and its arguments
 * Return: Always 0 (success)
 */

int execute(char *command, char *fullCommand[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/**
		 * child process
		 * execute the command,
		 * if not found (i.e execve returns -1) then print error message
		 */
		if (execve(command, fullCommand, NULL) == -1)
		{
			printf("%s: command not found\n", command);
			exit(1);
		}
	}
	else
	{
		/**
		 * parent process
		 * wait for child process to finish
		 */
		waitpid(pid, NULL, 0);
	}
	return (0);
}
