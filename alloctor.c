#include "shell.h"
/**
 *  _realloc - A func to reallocate block of memeory
 *  @ptr: Pointer to the block of memory
 *  @old_size: The size of ptr
 *  @new_size: The size we want to reallocate ptr to
 *  Return: Address of the new block, otherwie NUll
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *buffer;

	if (ptr == NULL)
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
		return (malloc(new_size));
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	buffer = malloc(new_size);

	if (buffer == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size < new_size)
		_memcpy(buffer, ptr, old_size);
	else
		_memcpy(buffer, ptr, new_size);

	free(ptr);
	return (buffer);
}
