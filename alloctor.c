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
	char *buffer;

	if(ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
		free(ptr);

	buffer = malloc(new_size);

	if (old_size < new_size)
	{
		buffer = _strncpy((char *) buffer, (char *)ptr, old_size);
		free(ptr);
	}
	else
	{
		buffer = _strncpy((char *)buffer, (char *)ptr, new_size);
		free(ptr);
	}
	return (buffer);
}
