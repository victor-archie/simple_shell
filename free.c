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

	while (ptr[p])
		free(ptr[p++]);
	free(ptr);
}
