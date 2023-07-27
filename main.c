#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - check the code
 *
 * Return: Always 0
 *
 */
int main(void)
{
	char *prompt = " ";

	simple_shell = argv[0];
	initialize_all_program_data();

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "($) ";
	runner(prompt);
	return (0);
}
