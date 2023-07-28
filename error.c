#include "shell.h"

/**
 * num_to_str - converts number to string
 * @n: number to be converted
 * Return: converted string
 */

char *num_to_str(int n)
{
	char *str;
	char *dup;
	int i, length;

	str = malloc(6 * sizeof(char));
	if (!str)
		exit(1);

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	for (i = 0; n; i++)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
	}
	str[i] = '\0';

	dup = _strdup(str);
	length = _strlen(str);

	for (i = 0; --length >= 0; ++i)
		str[i] = dup[length];
	free(dup);
	return (str);
}


/**
 * print_error - prints error message to stdout
 * @msg: message to be printed
 * Return: no return value
 */


void print_error(char *msg)
{
	write(STDERR_FILENO, msg, _strlen(msg));
}


/**
 * print_error_message - prints error message
 *
 * Return: no return value
 */


void print_error_message(void)
{
	char *err_no = num_to_str(execution_counter);

	print_error(program_name);
	print_error(": ");
	print_error(err_no);
	print_error(": ");
	print_error(tokens[0]);
	print_error(": ");

	if (errno == 126 || errno == 127)
		print_error(errno == 127 ? "not found\n" : "Permission denied\n");
	if (_strcmp(tokens[0], "cd") == 0)
	{
		print_error("can't cd to ");
		print_error(tokens[1]);
		print_error("\n");
	}

	free(err_no);
}
