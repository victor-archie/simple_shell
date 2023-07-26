#include "shell.h"
#include <unistd.h>

/**
 * char *simple_shell
 *
 */
int main(int argc, char *argv[])
{
	char *prompt = " ";

	simple_shell = argv[0];
	initialize_all_program_data();

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "($) ";
	runner(prompt);
	return (0);
}
