#include "lists.h"
/**
* add_nodeint_end - adds node to end
* @head: head of node
* @n: int added
* Return: add of the new element
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_element, *temp_element;

	temp_element = *head;
	new_element = malloc(sizeof(listint_t));
	if (new_element == NULL)
		return (NULL);

	new_element->n = n;
	new_element->next = NULL;

	if (*head == NULL)
		*head = new_element;
	else
	{
		while (temp_element->next != NULL)
			temp_element = temp_element->next;
		temp_element->next = new_element;
	}

	return (new_element);
}
