#include "lists.h"
/**
 * sum_listint - sum of data
 * @head: head of node
 * Return: Sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
