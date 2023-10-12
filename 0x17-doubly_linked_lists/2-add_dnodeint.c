#include "lists.h"

/**
 * add_dnodeint - function adds node in dlistint_t list
 * @head: head pointer
 * @n: element value
 * Return: new element address (Success), or (NULL)
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_elem;
	dlistint_t *h;

	new_elem = malloc(sizeof(dlistint_t));
	if (new_elem == NULL)
	{
		return (NULL);
	}

	new_elem->n = n;
	new_elem->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	new_elem->next = h;

	if (h != NULL)
	{
		h->prev = new_elem;
	}

	*head = new_elem;

	return (new_elem);
}
