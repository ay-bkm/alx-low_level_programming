#include "lists.h"
/**
 * free_list - frees the list
 * @head: Ptr to the head of the list
 * Return: Nothing
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
