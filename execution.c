#include "shell.h"

/**
 * find_path - to find path of the command
 * @cmd: command
 * Return: path
 */

char *find_path(char *cmd)
{
	char *path = _strdup(_getenv("PATH"));
	char *val, *dir;
	char *ful_path;
	int length;

	_strtok(path, "=");
	val = _strtok(NULL, "=");

	dir = _strtok(val, ":");

	while (dir)
	{
		length = (_strlen(cmd) + _strlen(dir) + 2);

		ful_path = malloc(length * sizeof(char));
		if (ful_path == NULL)
			exit(EXIT_FAILURE);

		_strcpy(ful_path, dir);
		_strcat(ful_path, "/");
		_strcat(ful_path, cmd);

		if (access(ful_path, F_OK) == 0)
		{
			free(path);
			return (ful_path);
		}

		free(ful_path);

		dir = _strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * execute - execute command passed to program
 *
 * Return: no return value
 */


void execute(void)
{
	pid_t pid;
	int stat;

	pid = fork();

	if (pid == -1)
	{
		exit(errno);
	}
	if (pid == 0)
	{
		execve(tokens[0], tokens, environ);
		exit(1);
	}

	if (pid > 0)
	{
		waitpid(pid, &stat, WUNTRACED);

		if (WIFEXITED(stat))
		{
			errno = WEXITSTATUS(stat);
		}
	}
}

/**
 * execute_binary - executes a binary command
 *
 * Return: 1 on success
 */


int execute_binary(void)
{
	char *cmd = tokens[0];
	char *path;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_0K) != 0 || access
				(cmd, X_OK) != 0)
		{
			errno = 127;
			return (-1);
		}
	}
	else
	{
		path = find_path(cmd);

		if (path == NULL)
		{
			errno = 127;
			return (-1);
		}

		free(tokens[0]);
		tokens[0] = path;
	}

	execute();
	return (0);
}
