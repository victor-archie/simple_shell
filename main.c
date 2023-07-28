#include "shell.h"

/**
 * main - run the shell program
 *
 * Return: Always 0
 *
 */
int main(void)
{
	char *prompt = " ";

	program_name = argv[0];
	initialize_all_program_data();

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "(V_SHELL$) ";

	runner(prompt);
	return (0);
}
