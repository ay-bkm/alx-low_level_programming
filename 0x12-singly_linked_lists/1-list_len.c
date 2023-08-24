#include "lists.h"

/**
 * list_len - length of list
 * @h: fist node
 * Return: Number of elements in list
 */
size_t list_len(const list_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
