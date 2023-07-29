#include "shell.h"


/**
 * loop - executes the shell infinite loop
 * when prompt is shown
 * @prompt: prompts the loop to excute
 * Return: always 0
 */

void loop(char *prompt)
{
	char **tokens = NULL;
	char *cur_cmdline = NULL;
	int execution_counter = 0;
	ssize_t size;
	int built_in, error;

	while (1)
	{
		execution_counter++;

		write(STDIN_FILENO, prompt, _strlen(prompt));

		size = _getline();

		if (size == 0)
			continue;

		_tokenize();

		built_in = error = is_builtin();

		if (built_in == NOT_BUILTIN)
		{
			error = execute_binary();
		}

		if (error != EXIT_SUCCESS)
		{
			print_error_message();
		}

		free_pointers_array(tokens);
		free(cur_cmdline);
	}
}
