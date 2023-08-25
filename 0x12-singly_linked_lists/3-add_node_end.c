#include "lists.h"

/**
 * add_node_end - adds new node the end of a list_t list.
 * @head: ptr to the heaad of the liist.
 * @str: string to be added to the new node.
 * Return: address of the new element, or NULL.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_element, *last_element;
	size_t len;

	len = strlen(str)
	last_element = *head
	new_element = malloc(sizeof(list_t));
	if (new_element == NULL)
		return (NULL);

	new_element->str = strdup(str);
	if (new_element->str == NULL)
	{
		free(new_element);
		return (NULL);
	}

	new_element->len = len;
	new_element->next = NULL;

	if (*head == NULL)
		*head = new_element;
	else
	{
		while (last_element->next != NULL)
			last_element = last_element->next;
		last_element->next = new_element;
	}

	return (new_element);
}
