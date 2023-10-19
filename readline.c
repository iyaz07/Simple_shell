#include "shell.h"
/**
 * _getline - Reads a line from a stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: Pointer to the input stream
 *
 * Return: The number of characters read, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, int file_descriptor)
{
	char *buffer;
	size_t i = 0;
	int c;

	file_descriptor = 0;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 256;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return -1;
	}

	buffer = *lineptr;

	while ((c = (char)_fgetc(file_descriptor)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			*lineptr = _realloc(*lineptr, *n, *n * 2);
			if (*lineptr == NULL)
			{
				free(buffer);
				return -1;
			}
			buffer = *lineptr;
		}

		buffer[i] = (char) c;
		i++;

		if (c == '\n')
			break;
	}

	buffer[i] = '\0';

	if (i == 0 && c == EOF)
		return -1;

	return i;
}
