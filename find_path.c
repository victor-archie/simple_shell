#include "shell.h"

int check_file(char *full_path);

/**
 * find_program - find a program in path
 * @data: a pointer to the program's data
 * Return: 0 if success, errcode otherwise
 */
int find_program(program_data *data)
{
	int i = 0, ret_code = 0;
	char **dir;

	if (!data->command_name)
		return (2);

	/**if is a full_path or an executable in the same path */
	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = _strcat(_strdup("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	dir = tokenize_path(data);

	if (!dir || !dir[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; dir[i]; i++)
	{/* appends the function_name to path */
		dir[i] = _strcat(dir[i], data->tokens[0]);
		ret_code = check_file(dir[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = _strdup(dir[i]);
			free_array_of_pointers(dir);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(dir);
	return (ret_code);
}

/**
 * tokenize_path - tokenize the path in directories
 * @data: a pointer to the program's data
 * Return: array of path directories
 */
char **tokenize_path(program_data *data)
{
	int d = 0;
	int count_dir = 2;
	char **tokens = NULL;
	char *PATH;

	/* get the PATH value*/
	PATH = _getkey("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{/*path not found*/
		return (NULL);
	}

	PATH = _strdup(PATH);

	/* find the number of directories in the PATH */
	for (d = 0; PATH[d]; d++)
	{
		if (PATH[d] == ':')
			count_dir++;
	}

	/* reserve space for the array of pointers */
	tokens = malloc(sizeof(char *) * count_dir);

	/*tokenize and duplicate each token of path*/
	d = 0;

	tokens[d] = _strdup(_strtok(PATH, ":"));
	while (tokens[d++])
	{
		tokens[d] = _strdup(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * check_file - checks if exists a file, if it is not a dairectory and
 * if it has excecution permisions for permisions.
 * @full_path: pointer to the full file name
 * Return: 0 on success, or error code if it exists.
 */
int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/*if not exist the file*/
	errno = 127;
	return (127);
}
