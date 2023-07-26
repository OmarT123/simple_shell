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

/**
 * _atoi - parses string into int
 * @s: input string
 * Return: int value of string
 */

int _atoi(char *s)
{
	int res = 0;
	char *temp = s;

	while (*temp < '0' || *temp > '9')
		temp++;
	while (*temp)
	{
		if (*temp < '0' || *temp > '9')
			return (-1);
		res = (res * 10) + (*temp - '0');
		temp++;
	}

	return ((*s == '-') ? -res : res);
}

