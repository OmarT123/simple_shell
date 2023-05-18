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
	int numArgs;
	char *argsTokens;

	while (1)
	{
		printf("#Shell$ ");
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
			command[length - 1] = '\0';
			numArgs = 0;
			argsTokens = strtok(command, " ");
			while (argsTokens != NULL && numArgs < MAX_ARGS)
			{
				fullCommand[numArgs++] = argsTokens;
				argsTokens = strtok(NULL, " ");
			}
			fullCommand[numArgs] = NULL;
			execute(fullCommand);
		}
	}
	return (0);
}

/**
 * execute - takes a command and its arguments and executes it
 * @fullCommand: command and its arguments
 * Return: Always 0 (success)
 */

int execute(char *fullCommand[])
{
	pid_t pid = fork();

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
