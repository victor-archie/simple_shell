#include "shell.h"

/**
 * *_getenv - gets an environment variable
 * @key: input key
 *
 * Return: value of the environment variable
 */

char *_getenv(const char *key)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], key, _strlen(key)) == 0)
		{
			return (environ[i]);
		}
	}

	return (NULL);
}

/**
 * _setenv - change or add an environment variable
 * @name: name of the variable to set
 * @value: new value
 * @overwrite: changes value of nameif nonzero and vice versa
 * if zero
 *
 * Return: 0 on success and -1 on error
 */

int _setenv(char *name, char *value, int overwrite)
{
	int i, name_len = 0, new_key = 1;
	char *env_var;

	if (name == NULL || value == NULL)
		return (1);

	name_len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) &&
				environ[i][name_len] == '=')
		{
			if (!overwrite)
				return (0);
			new_key = 0;

			free(environ[i]);
			break;
		}
	}

	env_var = _strcat(_strdup(name), "=");

	env_var = _strcat(env_var, value);

	if (new_key)
	{
		environ[i + 1] = NULL;
	}

	environ[i] = env_var;

	return (0);
}
