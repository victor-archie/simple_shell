#include "shell.h"

/**
 * expand_variables - expand variables
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
void expand_var(program_data *data)
{
	int i, n;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *tmp;

	if (data->input_line == NULL)
		return;
	buffer_add(line, data->input_line);
	for (i = 0; line[i]; i++)
		if (line[i] == '#')
			line[i--] = '\0';
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			num_to_string(errno, expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + i + 2);
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			num_to_string(getpid(), expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + i + 2);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			continue;
		else if (line[i] == '$')
		{
			for (n = 1; line[i + n] && line[i + n] != ' '; n++)
				expansion[n - 1] = line[i + n];
			tmp = _getkey(expansion, data);
			line[i] = '\0', expansion[0] = '\0';
			buffer_add(expansion, line + i + n);
			tmp ? buffer_add(line, tmp) : 1;
			buffer_add(line, expansion);
		}
	if (!_strcmp(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = _strdup(line);
	}
}

/**
 * expand_alias - expans aliases
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
void expand_alias(program_data *data)
{
	int i, n, expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *tmp;

	if (data->input_line == NULL)
		return;

	buffer_add(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (n = 0; line[i + n] && line[i + n] != ' '; n++)
			expansion[n] = line[i + n];
		expansion[n] = '\0';

		tmp = get_alias(data, expansion);
		if (tmp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + n);
			line[i] = '\0';
			buffer_add(line, tmp);
			line[_strlen(line)] = '\0';
			buffer_add(line, expansion);
			expanded = 1;
		}
		break;
	}
	if (expanded)
	{
		free(data->input_line);
		data->input_line = _strdup(line);
	}
}

/**
 * buffer_add - append string at end of the buffer
 * @buffer: buffer to be filled
 * @str_to_add: string to be copied in the buffer
 * Return: nothing, but sets errno.
 */
int buffer_add(char *buffer, char *str)
{
	int len, i;

	len = _strlen(buffer);
	for (i = 0; str[i]; i++)
	{
		buffer[len + i] = str[i];
	}
	buffer[len + i] = '\0';
	return (len + i);
}
