#include "main.h"

/**
 * main - Entry point, Reads command from user
 * and executes it until end of file
 * Return: Always 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *fullCommand[MAX_ARGS];
	ssize_t length;
	int numArgs, res;
	char *argsTokens;

	while (1)
	{
		printf(" ($) ");
		fflush(stdout);
		length = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
		if (length == -1)
		{
			perror("read");
		}
		else if (length == 0)
		{
			printf("\n");
			break;
		}
		else
		{
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';
			numArgs = 0;
			argsTokens = strtok(command, " ");
			while (argsTokens != NULL && numArgs < MAX_ARGS)
			{
				fullCommand[numArgs++] = argsTokens;
				argsTokens = strtok(NULL, " ");
			}
			fullCommand[numArgs] = NULL;
			if (numArgs == 0)
				continue;
			res = execute(fullCommand);
			if (res == -2)
				return (0);
		}
	}
	return (0);
}

/**
 * execute - takes a command and its arguments and executes it
 * @fullCommand: command and its arguments
 * Return: 0 on success, -1 if no command passed, -2 if command is exit
 */

int execute(char *fullCommand[])
{
	pid_t pid = fork();

	if (fullCommand[0] == NULL)
		return (-1);
	if (strcmp(fullCommand[0], "exit") == 0)
		return (-2);
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		/**
		 * child process
		 * execute the command,
		 * if not found (i.e execve returns -1) then print error message
		 */
		if (execve(fullCommand[0], fullCommand, NULL) == -1)
		{
			printf("./hsh: No such file or directory\n");
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
