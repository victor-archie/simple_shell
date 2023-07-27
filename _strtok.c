#include "shell.h"

/**
 * _strtpk - token a string into token (strtok)
 * @delim: delimiter
 * @str: string
 * Return: pointer to the next token or NULL
 */

char *_strtok(char *str, char *delim);
{
	static char *f;
	int a;
	char *token;

	if (str != NULL)
		f = str;

	for (; *f != '\0'; f++)
	{
		for (a = 0; delim[a] != '\0'; a++)
		{
			if (*f == delim[a])
				break;
		}
		if (delim[a] == '\0')
			break;
	}

	token = f;
	if (*token == '\0')
		return (NULL);

	for (; *f != '\0'; f++)
	{
		for (a = 0; delim[a] != '\0'; a++)
		{
			if (*f == delim[a])
			{
				*f = '\0';
				f++;
				return (token);
			}
		}
	}
	return (token);
}
