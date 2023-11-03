#include "h_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the hash table
 * Return: A pointer to the created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h_table;
	hash_node_t **arr;

	unsigned long int i = 0;

	if (size == 0)
	{
		return (NULL);
	}

	h_table = malloc(sizeof(hash_table_t));
	if (!h_table)
	{
		return (NULL);
	}

	arr = malloc(sizeof(*arr) * size);
	if (!arr)
	{
		free(h_table);
		return (NULL);
	}

	while (i < size)
	{
		arr[i] = NULL;
		i++;
	}

	h_table->size = size;
	h_table->array = arr;

	return (h_table);
}
