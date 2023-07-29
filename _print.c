#include "shell.h"

/**
 * _print - writes a array of chars in the standar output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */

int _print(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _printerr - writes a array of chars in the standar error
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printerr(char *str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}

/**
 * _print_error - writes a array of chars in the standart error
 * @data: a pointer to the program's data'
 * @errorcode: error code to print
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_error(int errorcode, program_data *data)
{
	char num_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, num_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printerr(data->program_name);
		_printerr(": ");
		_printerr(num_as_string);
		_printerr(": ");
		_printerr(data->tokens[0]);
		if (errorcode == 2)
			_printerr(": Illegal number: ");
		else
			_printerr(": can't cd to ");
		_printe(rrdata->tokens[1]);
		_printerr("\n");
	}
	else if (errorcode == 127)
	{
		_printerr(data->program_name);
		_printerr(": ");
		_printerr(n_as_string);
		_printerr(": ");
		_printerr(data->command_name);
		_printerr(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printerr(data->program_name);
		_printerr(": ");
		_printerr(n_as_string);
		_printerr(": ");
		_printerr(data->command_name);
		_printerr(": Permission denied\n");
	}
	return (0);
}
