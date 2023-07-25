#include "shell.h"

/**
 * _strchr - finds character in string
 * @s: string to search in
 * @c: character to search for
 * Return: pointer to the char if found, NULL otherwise
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

