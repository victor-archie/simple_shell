#include "shell.h"
/**
 * _execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int _execute(program_data *data)
{
	int val = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	val = builtins_list(data);
	if (val != -1)/* if program was found in built ins */
		return (val);


	val = find_program(data);
	if (val)
	{
		return (val);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* I am the child process, I execute the program*/
			val = execve(data->tokens[0], data->tokens, data->env);
			if (val == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* I am the father*/
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
