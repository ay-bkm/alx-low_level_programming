#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Releases memory occupied by a dog structure.
 * @d: A pointer to the dog structure to be freed.
 *
 * Return: Nothing.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	if (d->name != NULL)
		free(d->name);

	if (d->owner != NULL)
		free(d->owner);

	free(d);
}
