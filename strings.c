#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 */
int _strlen(char *string)
{
	int l = 0;

	if (string == NULL)
		return (0);

	while (string[l+] != '\0')
	{
	}
	return (--l);
}

/**
 * _strdup - duplicates an string
 * @string: String to be copied
 * Return: pointer to the array
 */
char *_strdup(char *string)
{
	char *dest;
	int len, i;

	if (string == NULL)
		return (NULL);

	len = _strlen(string) + 1;

	dest = malloc(sizeof(char) * len);

	if (dest == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len ; i++)
	{
		dest[i] = string[i];
	}

	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @string1: String one, or the shorter
 * @string2: String two, or the longer
 * @number: number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */
int _strcmp(char *string1, char *string2, int number)
{
	int i;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0) /* infinite longitud */
	{
		if (_strlen(string1) != _strlen(string2))
			return (0);
		for (i = 0; string1[i]; i++)
		{
			if (string1[i] != string2[i])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (i = 0; i < number ; i++)
		{
			if (string1[i] != string2[i])
			return (0);
		}
		return (1);
	}
}

/**
 * _strcat - concatenates two strings.
 * @string1: String to be concatenated
 * @string2: String to be concatenated
 *
 * Return: pointer to the array
 */
char *str_concat(char *string1, char *string2)
{
	char *dest;
	int len1 = 0, len2 = 0;

	if (string1 == NULL)
		string1 = "";
	len1 = _strlen(string1);

	if (string2 == NULL)
		string2 = "";
	len2 = _strlen(string2);

	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (dest == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of string1 */
	for (len1 = 0; string1[len1] != '\0'; len1++)
		dest[len1] = string1[len1];
	free(string1);

	/* copy of string2 */
	for (len2 = 0; string2[len2] != '\0'; len2++)
	{
		dest[len1] = string2[len2];
		len1++;
	}

	dest[len1] = '\0';
	return (dest);
}


/**
 * _strrev - reverses a string.
 *
 * @string: pointer to string.
 * Return: void.
 */
void _strrev(char *string)
{

	int i = 0, l = _strlen(string) - 1;
	char holder;

	while (i < l)
	{
		holder = string[i];
		string[i++] = string[l];
		string[l--] = holder;
	}
}
