#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - prints a string to stdout
 * @s: input string
 * Return: On success 1, On error -1
 */

int _print_string(char *s)
{
	int i;

	for (i = 0; i < _strlen(s); i++)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
	return (0);
}

