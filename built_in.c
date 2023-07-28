#include "shell.h"

/**
 * builtin_exit - handles the exit builtin command
 * Return: exit status
 */

int builtin_exit(void)
{
	int i, stat = 0;

	if (tokens[i] != NULL)
		stat = _atoi(tokens[1]);

	free_pointers_array(tokens);
	free(cur_cmdline);
	exit(stat);
}


/**
 * builtin_env - handles the env builtin command
 * Return: 0 on success
 */

int builtin_env(void)
{
	int i;

	(void)tokens;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i],
				_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}


/**
 * builtin_cd - handles the cd builtin command
 * Return: 0 on success
 */

int builtin_cd(void)
{
	char dir[1024] = {'\0'};

	if (tokens[1] == NULL)
	{
		errno = 127;
		return (-1);
	}

	if (chdir(tokens[1]) == -1)
	{
		return (-1);
	}

	getcwd(dir, 1024);

	_setenv("PWD", dir, 0);
	return (0);
}

/**
 * is_builtin - handles builtin command
 * Return: NOT_BUILTIN if it is not a builtin command
 */


int is_builtin(void)
{
	builtin_action actions[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"cd", builtin_cd},

		{NULL, NULL}};

	int j;

	for (j = 0; actions[j].name; j++)
	{
		if (_strcmp(actions[j].name, tokens[0]) == 0)
		{
			return (actions[j].actions());
		}
	}

	return (NOT_BUILTIN);
}
