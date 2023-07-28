#include "shell.h"

/**
 * free - frees the memory space pointed to by ptr
 * @ptr: pointer
 *
 * Return 0 (void)
 */
void free_pointers_array(char **ptr)
{
	int p = 0;

	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
