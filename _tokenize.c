#include "shell.h"

/**
 * _tokenize - splits an array of strings into tokens
 *
 * Return - void
 */

void _tokenize(void)
{
	char **_token;
	char *token;
	int id = 0;

	_token = malloc(32 * sizeof(char *));
	if (_token == NULL)
		exit(1);

	token = _strtok(cur_cmdline, " ");

	while (token)
	{
		_token[id++] = _strdup(token);
		token = _strtok(NULL, " ");
	}

	tokens = _token;
}
