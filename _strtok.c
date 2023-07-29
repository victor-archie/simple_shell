#include "shell.h"
/**
 * _strtok - separates strings into tokens
 * @line: It´s pointer to array we receive in getline.
 * @delim: It´s characters we mark off string in parts.
 * Return: A pointer to the created token
*/
char *_strtok(char *line, char *delim)
{
	int n;
	static char *str;
	char *strcpy;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (n = 0; delim[j] != '\0'; n++)
		{
			if (*str == delim[n])
			break;
		}
		if (delim[n] == '\0')
			break;
	}
	strcpy = str;
	if (*strcpy == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (n = 0; delim[n] != '\0'; n++)
		{
			if (*str == delim[n])
			{
				*str = '\0';
				str++;
				return (strcpy);
			}
		}
	}
	return (strcpy);
}
