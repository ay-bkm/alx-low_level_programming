#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 *_calloc - works just like standard calloc
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to new allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *m1;

	m1 = NULL;
	if (nmemb == 0 || size == 0)
		return (NULL);
	m1 = malloc(nmemb * size);
	if (m1 == NULL)
		return (NULL);
	memset(m1, 0, nmemb * size);
	return (m1);
}
