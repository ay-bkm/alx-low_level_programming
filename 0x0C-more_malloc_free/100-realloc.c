#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocated memory
 * @ptr: pointer to old memory
 * @old_size: size of the old memory
 * @new_size: size of the new memory
 * Return: pointer to the new memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
