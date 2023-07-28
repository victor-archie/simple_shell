#include "shell.h"

/**
 * _strcmp - to compare two strings with specified length
 * @s1: string one
 * @s2: string two
 * @i: length of string
 * Return: 0 on success
 */

int _strncmp(const char *s1, const char *s2, size_t i)
{
	int n;


	for (n = 0; n < i; n++)
	{
		if (s1[n] != s2[n])
		{
			return (s1[n] - s2[n]);
		}
		if (s1[n] == '\0')
		{
			break;
		}
	}
	return (0);
}
