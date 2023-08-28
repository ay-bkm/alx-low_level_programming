#include "lists.h"
/**
 * listint_len - lists elements
 * @h: argument list
 * Return: n of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t counter;
	const listint_t *curr;

	curr = h
	counter = 0
	while (curr != NULL)
	{
		counter++;
		curr = curr->next;
	}

	return (counter);
}
