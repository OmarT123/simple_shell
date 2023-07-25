#include "shell.h"

/**
 * _strlen - finds length of string
 * @s: input string
 * Return: length of s
 */

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: negative if s1 < s2, positive if s2 < s1, 0 if equal
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: string to be added to destination
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *res = dest;

	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (res);
}

/**
 * _strdup - duplicates a string
 * @s: input string
 * Return: pointer to new string
 */

char *_strdup(char *s)
{
	int len = _strlen(s);
	char *res;
	int i;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		perror("malloc");
	for (i = 0; i < len; i++)
	{
		res[i] = s[i];
	}
	res[i] = '\0';
	return (res);
}

/**
 * _strcpy - copies the content of a string to another
 * @dest: destination string
 * @src: source string
 * Return: pointer to new string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	if (src == NULL || dest == NULL)
		return (dest);
	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
