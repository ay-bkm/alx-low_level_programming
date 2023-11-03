#include "h_tables.h"

/**
 * create_and_add_node - Allocate memory, assign values, and insert a node into the hash table
 * @ht: Hash table
 * @key: Key; must not be an empty string
 * @value: Value
 * @idx: Index to insert in the hash table
 * Return: 1 if successful, 0 if failed
 */
int create_and_add_node(hash_table_t *ht, const char *key, const char *value,
		unsigned long int idx)
{
	hash_node_t *node = NULL;
	char *k;
	char *v;

	node = malloc(sizeof(hash_node_t));
	if (!node)
	{
		return 0;
	}

	k = strdup(key);
	if (!k)
	{
		free(node);
		return 0;
	}

	v = strdup(value);
	if (!v)
	{
		free(k);
		free(node);
		return 0;
	}

	node->key = k;
	node->value = v;

	if ((ht->array)[idx] == NULL)
		node->next = NULL;
	else
		node->next = (ht->array)[idx];
	(ht->array)[idx] = node;

	return 1;
}

/**
 * hash_table_set - Add an element to the hash table
 * @ht: Hash table
 * @key: Key; must not be an empty string
 * @value: Value
 * Return: 1 if successful, 0 if failed
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* Get index */
	/* If the key already exists, update the value and return */
	/* Else, create a node */
	/* Set ht index pointer to node; else, add node to the front if collision */

	unsigned long int idx;
	hash_node_t *node = NULL;
	char *v;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
	{
		return 0;
	}

	idx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[idx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;

	if (node != NULL)
	{
		v = strdup(value);
		if (!v)
		{
			return 0;
		}
		if (node->value)
			free(node->value);
		node->value = v;
		return 1;
	}

	return create_and_add_node(ht, key, value, idx);
}
