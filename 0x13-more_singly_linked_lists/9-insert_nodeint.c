/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head of the listint_t list.
 * @idx: The index of the list where the new node should be added.
 * @n: The integer data for the new node.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *inserted_node, *temp_node;
	unsigned int new_idx;

	new_idx = 0;
	temp_node = *head;
	inserted_node = malloc(sizeof(listint_t));
	if (!inserted_node)
		return (NULL);

	inserted_node->n = n;

	if (!idx)
	{
		inserted_node->next = temp_node;
		*head = inserted_node;
		return (inserted_node);
	}

	while (temp_node)
	{
		if (new_idx == idx - 1)
		{
			inserted_node->next = temp_node->next;
			temp_node->next = inserted_node;
			return (inserted_node);
		}
		new_idx++;
		temp_node = temp_node->next;
	}

	free(inserted_node);
	return (NULL);
}
