#include "shell.h"

char **tokens;
char *cur_cmdline;

/**
 * initialize_all_program_data - to initialize all the data input
 *
 * Return: 0 on success
 */
void initialize_all_program_data(void)
{
	tokens = NULL;
	cur_cmdline = NULL;
}
