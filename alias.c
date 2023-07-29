#include "shell.h"

/**
 * print_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int print_alias(program_data *data, char *alias)
{
	int m, n, len;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		len = _strlen(alias);
		for (m = 0; data->alias_list[m]; m++)
		{
			if (!alias || (_strcmp(data->alias_list[m], alias, len)
				&&	data->alias_list[m][len] == '='))
			{
				for (n = 0; data->alias_list[m][n]; n++)
				{
					buffer[n] = data->alias_list[m][n];
					if (data->alias_list[m][n] == '=')
						break;
				}
				buffer[n + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[m] + n + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */
char *get_alias(program_data *data, char *name)
{
	int l, len;

	/* validate the arguments */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	len = _strlen(name);

	for (l = 0; data->alias_list[l]; l++)
	{/* Iterates through the environ and check for coincidence of the varname */
		if (_strcmp(name, data->alias_list[l], len) &&
			data->alias_list[l][len] == '=')
		{/* returns the value of the key NAME=  when find it */
			return (data->alias_list[l] + len + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);

}

/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_alias(char *alias_string, program_data *data)
{
	int j, i;
	char buffer[250] = {'0'}, *tmp = NULL;

	/* validate the arguments */
	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	/* Iterates alias to find = char */
	for (j = 0; alias_string[j]; j++)
		if (alias_string[j] != '=')
			buffer[j] = alias_string[j];
		else
		{/* search if the value of the alias is another alias */
			tmp = get_alias(data, alias_string + j + 1);
			break;
		}

	/* Iterates through the alias list and check for coincidence of the varname */
	for (i = 0; data->alias_list[i]; i++)
		if (_strcmp(buffer, data->alias_list[i], j) &&
			data->alias_list[i][j] == '=')
		{/* if the alias alredy exist */
			free(data->alias_list[i]);
			break;
		}

	/* add the alias */
	if (tmp)
	{/* if the alias already exist */
		buffer_add(buffer, "=");
		buffer_add(buffer, tmp);
		data->alias_list[i] = _strdup(buffer);
	}
	else /* if the alias does not exist */
		data->alias_list[i] = _strdup(alias_string);
	return (0);
}
