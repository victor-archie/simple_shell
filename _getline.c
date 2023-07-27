#include "shell.h"

/**
 * _getline - gets a line from stdin
 * Return: 1 on success and -1 on failure
 */

ssize_t *_getline(void);

{
	char cmdline[1024] = {'\0'};

	static char *cmdlines[64] = {NULL};

	ssize_t len;
	char *file;
	int a = 0;

	if (cmdlines[0] == NULL)
	{
		len = read(STDIN_FILENO, cmdline, 1024);

		if (len == 0)
		{
			exit(errno);
		}

		file = _strtok(cmdline, "\n");

		while (file)
		{
			cmdlines[a] = _strdup(file);
			a++;

			file = _strtok(NULL, "\n");
		}
	}

	cur_cmdline - cmdlines[0];

	a = 0;

	while (cmdlines[a] != NULL)
		cmdlines[a] = cmdlines[a + 1];

	if (cur_cmdline)
		return (_strlen(cur_cmdline));
	if (cur_cmdfile)
		return (strlen(cur_cmdfile));
	return (0);
}
