#include "lists.h"
/**
 * free_listint - frees the list
 * @head: The head of the node
 */
void free_listint(listint_t *head)
{
	listint_t *tempo;

	while (head != NULL)
	{
		tempo = head;
		head = head->next;
		free(tempo->n);
		free(tempo);
	}
}
