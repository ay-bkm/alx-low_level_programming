#include "lists.h"
/**
 * pop_listint - deletes head
 * @head: the head
 * Return: data of node
 */
int pop_listint(listint_t **head)
{
	listint_t *curr;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	curr = *head;
	n = (*head)->n;
	*head = (*head)->next;
	free(curr);

	return (n);
}
