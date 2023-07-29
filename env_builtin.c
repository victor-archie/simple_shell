#include "shell.h"

/**
 * builtin_env - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_env(program_data *data)
{
	int j;
	char cpname[50] = {'\0'};
	char *var_cpy = NULL;

	/* if not arguments */
	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (j = 0; data->tokens[1][j]; j++)
		{/* checks if exists a char = */
			if (data->tokens[1][j] == '=')
			{/* checks if exists a var with the same name and change its value*/
			/* temporally */
				var_cpy = _strdup(_getkey(cpname, data));
				if (var_cpy != NULL)
					_setkey(cpname, data->tokens[1] + j + 1, data);

				/* print the environ */
				print_environ(data);
				if (_getkey(cpname, data) == NULL)
				{/* print the variable if it does not exist in the environ */
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{/* returns the old value of the var*/
					_setkey(cpname, var_cpy, data);
					free(var_cpy);
				}
				return (0);
			}
			cpname[j] = data->tokens[1][j];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - ..
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_set_env(program_data *data)
{
	/* validate args */
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	_setkey(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * builtin_unset_env - ..
 * @data: struct for the program's data'
 * Return: ..
 */
int builtin_unset_env(program_data *data)
{
	/* validate args */
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	_remove_key(data->tokens[1], data);

	return (0);
}
