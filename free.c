#incllude "shell.h"

/**
 * free - frees the memory space pointed to by ptr
 * @ptr: pointer
 *
 * Return 0 (void)
 */
void free(void *ptr)
{
	int i = 0;

	while (arr[i])
		free(arr[i++]);
	free(arr);
}
