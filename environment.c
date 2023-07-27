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
		if (_strcmp(environ[i], key, _strlen(key)) == 0)
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
	if (name == NULL || *name == '\0')
	{
		return (-1);
	}

	return (_update_env_var(key, value, overwrite));
}

/**
 * _update_env_var - change or add an environment variable
 * @key: name of the variable to set
 * @value: new value
 * @overwrite: changes value of nameif nonzero and vice versa
 * if zero
 *
 * Return: 0 on success, -1 on error.
 */

int _update_env_var(const char *key, const char *value, int overwrite)
{
	char **environ;
	size_t key_len = _strlen(key);

	for (char **env = environ; *env != NULL; ++env)
	{
		if (_strcmp(*env, key, key_len) == 0 && (*env)[key_len] == '=')
		{
			if (overwrite)
			{
				char *new_var = _strcat(key, "=");
				char *old_value = (*env) + key_len + 1;
				char *new_value = _strcat(new_var, value);

				free(new_var);
				if (new_value == NULL)
					return (-1);

				free(*env);
				*env = new_value;
			}
			return (0); /* Variable found and updated */
		}
	}
	char *new_var = _strcat(key, "=");
	char *new_value = _strcat(new_var, value);

	free(new_var);

	if (new_value == NULL)
		return (-1); /* Memory allocation failed */
	char **end_env = environ;

	while (*end_env)
		++end_env;

	*end_env = new_value;
	++end_env;
	*end_env = NULL;
	return (0);
}
