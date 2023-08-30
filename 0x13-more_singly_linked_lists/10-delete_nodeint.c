#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes the node at index
 * @head: head of node
 * @index: index of deleted node
 * Return: -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *previous;
	unsigned int node_index;

	node_index = 0
	if (!*head)
		return (-1);

	temp = *head;
	if (!index)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (temp)
	{
		if (node_index == index)
		{
			previous->next = temp->next;
			free(temp);
			return (1);
		}
		node_index++;
		previous = temp;
		temp = temp->next;
	}

	return (-1);
}
