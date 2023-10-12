#include "lists.h"

/**
 * free_dlistint - function that frees dlistint_t list
 * @head: head pointer
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *head_ptr;

	if (head != NULL)
	{
		while (head->prev != NULL)
		{
			head = head->prev;
		}
	}

	while ((head_ptr = head) != NULL)
	{
		head = head->next;
		free(head_ptr);
	}
}
