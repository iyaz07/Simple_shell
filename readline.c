#include "shell.h"
/**
 * _getline - Read a line of text from a file descriptor.
 *
 * @lineptr: Pointer to the line buffer.
 * @n: Pointer to the size of the buffer.
 * @file_descriptor: The file descriptor to read from.
 *
 * Return: Number of bytes read, or -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, int file_descriptor)
{
	char *buffer;
	size_t i = 0;
	int c;

	file_descriptor = 0;
	if (*lineptr == NULL || *n == 0)
		*n = 1024;
	*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
		return (-1);
	buffer = *lineptr;
	while ((c = (char)_fgetc(file_descriptor)) != EOF)
	{
		if (i >= *n - 1)
		{
			buffer = realloc_buffer(buffer, n);

			if (buffer == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = buffer;
		}
		buffer[i] = (char) c;
		i++;
		if (c == '\n')
			break;
	}
	buffer[i] = '\0';
	if (i == 0 && c == EOF)
	{
		free(*lineptr);
		return (-1);
	}
	return (i);
}
/**
 * realloc_buffer - Reallocate memory for a buffer.
 *
 * @buffer: A pointer to the buffer to be reallocated.
 * @n: A pointer to the size of the buffer.
 *
 * Return: A pointer to the reallocated buffer or NULL on failure.
 */
char *realloc_buffer(char *buffer, size_t *n)
{
	char *new_buffer;

	*n *= REALLOCATION_FACTOR;
	new_buffer = _realloc(buffer, *n, *n * 2);

	if (new_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	return (new_buffer);
}
