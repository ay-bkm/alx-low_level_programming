#include "h_tables.h"

/**
 * hash_table_get - Retrieve value associated with a given key
 * @ht: Hash table
 * @key: Key to search for
 * Return: The value associated with the key; NULL if the key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (!ht || !key)
	{
		return (NULL);
	}

	idx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[idx];
	while (node != NULL && strcmp(node->key, key) != 0)
	{
		node = node->next;
	}

	if (!node)
	{
		return (NULL);
	}
	else
	{
		return (node->value);
	}
}
