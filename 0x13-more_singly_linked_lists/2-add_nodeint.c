#include "lists.h"
/**
 * add_nodeint - adds node to the beginning
 * @head: head of the node
 * @n: number
 * Return: new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *added_node = malloc(sizeof(listint_t));

	if (added_node == NULL)
		return (NULL);

	added_node->n = n;
	added_node->next = *head;
	*head = added_node;

	return (added_node);
}
