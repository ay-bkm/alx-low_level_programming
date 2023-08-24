#include "lists.h"

/**
 * add_node - adds a node at the beginning of a list_t
 * @head: pointer to the head
 * @str: string to be added to the first node
 * Return: the address of the new node, or NULL if fail.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *first_node;

	if (head == NULL || str == NULL)
		return (NULL);

	first_node = malloc(sizeof(list_t));
	if (first_node == NULL)
		return (NULL);

	first_node->str = strdup(str);
	if (first_node->str == NULL)
	{
		free(first_node);
		return (NULL);
	}

	first_node->len = strlen(str);
	first_node->next = *head;
	*head = first_node;

	return (first_node);
}
