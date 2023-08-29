#include "lists.h"
/**
 * pop_listint - deletes head
 * @head: the head
 * Return: data of node
 */
int pop_listint(listint_t **head)
{
	listint_t *curr;
	int num;

	if (head == NULL || *head == NULL)
		return (0);

	curr = *head;
	num = (*head)->num;
	*head = (*head)->next;
	free(curr);

	return (num);
}
