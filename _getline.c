#include "shell.h"

/**
* _getline - read one line from the prompt.
* @data: struct for the program's data
*
* Return: reading counting bytes.
*/
int _getline(program_data *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_cmd[10] = {NULL};
	static char array_op[10] = {'\0'};
	ssize_t bytes, i = 0;

	/* check if doesnot exist more commands in the array */
	/* and checks the logical operators */
	if (!array_cmd[0] || (array_op[0] == '&' && errno != 0) ||
		(array_op[0] == '|' && errno == 0))
	{
		/*free the memory allocated in the array if it exists */
		for (i = 0; array_cmd[i]; i++)
		{
			free(array_cmd[i]);
			array_cmd[i] = NULL;
		}

		/* read from the file descriptor int to buff */
		bytes = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes == 0)
			return (-1);

		/* split lines for \n or ; */
		i = 0;
		do {
			array_cmd[i] = _strdup(_strtok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = check_logic_ops(array_cmd, i, array_op);
		} while (array_cmd[i++]);
	}

	/*obtains the next command (command 0) and remove it for the array*/
	data->input_line = array_cmd[0];
	for (i = 0; array_cmd[i]; i++)
	{
		array_cmd[i] = array_cmd[i + 1];
		array_op[i] = array_op[i + 1];
	}

	return (_strlen(data->input_line));
}


/**
* check_logic_ops - checks and split for && and || operators
* @array_commands: array of the commands.
* @i: index in the array_commands to be checked
* @array_operators: array of the logical operators for each previous command
*
* Return: index of the last command in the array_commands.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *tmp = NULL;
	int j;

	/* checks for the & char in the command line*/
	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			/* split the line when chars && was found */
			tmp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _strdup(array_commands[i]);
			array_commands[i + 1] = _strdup(tmp + j + 2);
			i++;
			array_operators[i] = '&';
			free(tmp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			/* split the line when chars || was found */
			tmp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _strdup(array_commands[i]);
			array_commands[i + 1] = _strdup(tmp + j + 2);
			i++;
			array_operators[i] = '|';
			free(tmp);
			j = 0;
		}
	}
	return (i);
}
