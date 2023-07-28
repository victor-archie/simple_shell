#include "shell.h"

/**
 * *_strcpy - copies a string from one destination
 * to another.
 * @dest: pointer to destination
 * @src: pointer to the source being copied from
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0, len = 0;

	while (src[len] != '\0')
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}


/**
 * *_strcat - concatenate two strings
 * @dest: char string to concatenate to
 * @src: char string
 * Return: pointer to resulting string `dest`
 */

char *_strcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - to find the length of a string.
 * @string: pointer to the string
 *
 * Return: length of string
 */

size_t _strlen(const char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * *_strdup - duplicates strings
 * @str: pointer to string to be duplicated
 *
 * Return: duplicated string
 */

char *_strdup(const char *str)
{
	size_t length = _strlen(str);

	char *dup;

	dup = (char *)malloc((length + 1) * sizeof(char));

	if (dup != NULL)
	{
		_strcpy(dup, str);
	}

	return (dup);
}

/**
 * _strcmp - Compare two strings
 * @s1: string
 * @s2: string
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
