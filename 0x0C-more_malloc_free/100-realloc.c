#include "main.h"
#include <stdlib.h>
#include <string.h>
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

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
	free(ptr);

	return (new_ptr);
}
