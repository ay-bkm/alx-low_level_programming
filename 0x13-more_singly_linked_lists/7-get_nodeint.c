#include "lists.h"
/**
 * get_nodeint_at_index - nth node
 * @head: head of node
 * @index: index of node
 * Return: nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	for (j = 0; head != NULL && j < index; j++)
		head = head->next;

	return (head == NULL ? NULL : head);
}
