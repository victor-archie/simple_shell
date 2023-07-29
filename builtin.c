#include "shell.h"

/**
 * builtin_exit - exit of the program with the status
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(program_data *data)
{
	int j;

	if (data->tokens[1] != NULL)
	{/*if exists arg for exit, check if is a number*/
		for (j = 0; data->tokens[1][j]; j++)
			if ((data->tokens[1][j] < '0' || data->tokens[1][j] > '9')
				&& data->tokens[1][j] != '+')
			{/*if is not a number*/
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_all_data(data);
	exit(errno);
}


/**
 * builtin_cd - change the current directory
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(program_data *data)
{
	char *home_dir = _getkey("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (_strcmp(data->tokens[1], "-", 0))
		{
			dir_old = _getkey("OLDPWD", data);
			if (dir_old)
				error_code = set_work_directory(data, dir_old);
			_print(_getkey("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!home_dir)
			home_dir = getcwd(old_dir, 128);

		return (set_work_directory(data, home_dir));
	}
	return (0);
}


/**
 * set_work_directory - set the work directory
 * @data: struct for the program's data
 * @new_dir: path to be set as work directory
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_work_directory(program_data *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!_strcmp(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		_setkey("PWD", new_dir, data);
	}
	_setkey("OLDPWD", old_dir, data);
	return (0);
}


/**
 * builtin_help - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_help(program_data *data)
{
	int i, len = 0;
	char *msg[6] = {NULL};

	msg[0] = HELP_MSG;

	/* validate args */
	if (data->tokens[1] == NULL)
	{
		_print(msg[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	msg[1] = HELP_EXIT_MSG;
	msg[2] = HELP_ENV_MSG;
	msg[3] = HELP_SETENV_MSG;
	msg[4] = HELP_UNSETENV_MSG;
	msg[5] = HELP_CD_MSG;

	for (i = 0; msg[i]; i++)
	{
		/*print the length of string */
		len = _strlen(data->tokens[1]);
		if (_strcmpe(data->tokens[1], msg[i], len))
		{
			_print(msg[i] + len + 1);
			return (1);
		}
	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}


/**
 * builtin_alias - add, remove or show aliases
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_alias(program_data *data)
{
	int i = 0;

	/* if there are no arguments, print all environment */
	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++i])
	{/* if there are arguments, set or print each env variable*/
		if (count_characters(data->tokens[i], "="))
			set_alias(data->tokens[i], data);
		else
			print_alias(data, data->tokens[i]);
	}

	return (0);
}
