#include "shell.h"
/**
 * freemem - Free memory allocated for an array of strings.
 *
 * @av: The array of strings to be freed.
 */
void freemem(char **av)
{
	int i = 0;

	for (i = 0; av[i] != NULL; i++)
		free(av[i]);

	free(av);
}

/**
 * _memcpy - copies information from one memory to another
 *
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
	char_newptr[i] = '\0';
}
