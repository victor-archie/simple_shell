#include "shell.h"

/**
 * *_strcpy - copies a string from one destination
 * to another.
 * @dest: pointer to destination
 * @src: pointer to the source being copied from
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

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

char *_strcat(char *dest, char *src)
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

size_t _strlen(char *string)
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
