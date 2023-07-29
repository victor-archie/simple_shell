#include "shell.h"

char *program_name;

/**
 * main - run the shell program
 *
 * Return: Always 0
 *
 */

int main(int argc, char *argv[])
{
	char *prompt = " ";

	(void)argc;

	program_name = argv[0];
	initialize_all_program_data();

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "(V_SHELL$) ";

	loop(prompt);
	return (0);
}
