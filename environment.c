#include "shell.h"

/**
 * _getkey - gets the value of an environment variable
 * @key: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */
char *_getkey(char *key, program_data *data)
{
	int i, key_len = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);

	/* obtains the leng of the variable requested */
	key_len = _strlen(key);

	for (i = 0; data->env[i]; i++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (_strcmp(key, data->env[i], key_leng) &&
		 data->env[i][key_len] == '=')
		{/* returns the value of the key NAME=  when find it*/
			return (data->env[i] + key_len + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);
}

/**
 * _setkey - overwrite the value of the environment variable
 * or create it if does not exist.
 * @key: name of the variable to set
 * @value: new value
 * @data: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int _setkey(char *key, char *value, program_data *data)
{
	int i, key_len = 0, new_key = 1;

	/* validate the arguments */
	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	/* obtains the leng of the variable requested */
	key_len = _strlen(key);

	for (i = 0; data->env[i]; i++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (_strcmp(key, data->env[i], key_len) &&
		 data->env[i][key_len] == '=')
		{/* If key already exists */
			new_key = 0;
			/* free the entire variable, it is new created below */
			free(data->env[i]);
			break;
		}
	}
	/* make an string of the form key=value */
	data->env[i] = _strcat(_strdup(key), "=");
	data->env[i] = _strcat(data->env[i], value);

	if (new_key)
	{/* if the variable is new, it is create at end of actual list and we need*/
	/* to put the NULL value in the next position */
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * _remove_key - remove a key from the environment
 * @key: the key to remove
 * @data: the sructure of the program's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int _remove_key(char *key, program_data *data)
{
	int i, key_len = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (0);

	/* obtains the leng of the variable requested */
	key_len = _str_len(key);

	for (i = 0; data->env[i]; i++)
	{/* iterates through the environ and checks for coincidences */
		if (_strcmp(key, data->env[i], key_len) &&
		 data->env[i][key_len] == '=')
		{/* if key already exists, remove them */
			free(data->env[i]);

			/* move the others keys one position down */
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			/* put the NULL value at the new end of the list */
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */
void print_environ(program_data *data)
{
	int n;

	for (n = 0; data->env[n]; n++)
	{
		_print(data->env[n]);
		_print("\n");
	}
}
