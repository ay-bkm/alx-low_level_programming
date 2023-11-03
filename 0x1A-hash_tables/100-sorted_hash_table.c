#include "h_tables.h"

/**
 * shash_table_create - Create a sorted hash table given a size
 * @size: Size of the hash table
 * Return: Pointer to the table; NULL if an error occurs
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **array;
	unsigned long int i = 0;

	if (size == 0)
	{
		return (NULL);
	}

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
	{
		return (NULL);
	}

	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(ht);
		return (NULL);
	}

	while (i < size)
	{
		array[i] = NULL;
		i++;
	}

	ht->size = size;
	ht->array = array;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_to_sorted_list - Compare keys and insert a node into a sorted list (for printing)
 * @ht: Sorted hash table
 * @node: Node to insert
 * Return: 1 if successful, 0 if failed
 */
int insert_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (!(ht->shead)) /* If empty hash table, initialize head and tail nodes */
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	if (strcmp(node->key, (ht->shead)->key) <= 0) /* Insert at the beginning */
	{
		node->snext = ht->shead;
		(ht->shead)->sprev = node;
		ht->shead = node;
	}
	else if (strcmp(node->key, (ht->stail)->key) > 0) /* Insert at the end */
	{
		node->sprev = ht->stail;
		(ht->stail)->snext = node;
		ht->stail = node;
	}
	else /* Insert in the middle */
	{
		tmp = ht->shead;
		while (tmp->snext && strcmp(node->key, (tmp->snext)->key) > 0)
			tmp = tmp->snext;
		node->snext = tmp->snext;
		node->sprev = tmp;
		(tmp->snext)->sprev = node;
		tmp->snext = node;
	}
	return (1);
}

/**
 * create_and_add_node - Malloc, set values, and insert a node into the hash table
 * @ht: Sorted hash table
 * @key: Key; can't be an empty string
 * @value: Value
 * @idx: Index to insert in the hash table
 * Return: 1 if successful, 0 if failed
 */
int create_and_add_node(shash_table_t *ht, const char *key, const char *value,
						unsigned long int idx)
{
	shash_node_t *node = NULL;
	char *k;
	char *v;
	(void)idx;

	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (0);

	k = strdup(key);
	if (!k)
	{
		free(node);
		return (0);
	}

	v = strdup(value);
	if (!v)
	{
		free(k);
		free(node);
		return (0);
	}

	node->key = k;
	node->value = v;
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	if ((ht->array)[idx] == NULL)
		node->next = NULL;
	else
		node->next = (ht->array)[idx];
	(ht->array)[idx] = node;

	return (insert_to_sorted_list(ht, node));
}

/**
 * shash_table_set - Add an element to a sorted hash table
 * @ht: Hash table
 * @key: Key; can't be an empty string
 * @value: Value
 * Return: 1 if successful, 0 if failed
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node = NULL;
	char *v;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
	{
		return (0);
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
			return (0);
		}
		if (node->value)
			free(node->value);
		node->value = v;
		return (1);
	}

	return (create_and_add_node(ht, key, value, idx));
}

/**
 * shash_table_get - Given a key, get the value
 * @ht: Hash table
 * @key: Key
 * Return: Value; or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *tmp;

	if (!ht || !key)
	{
		return (NULL);
	}
	idx = key_index((const unsigned char *)key, ht->size);

	tmp = (ht->array)[idx];
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (!tmp)
	{
		return (NULL);
	}
	else
		return (tmp->value);
}

/**
 * shash_table_print - Print key/values of the hash table in ascending order
 * @ht: Hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *comma = "";

	if (!ht || !ht->array)
	{
		return;
	}

	putchar('{');
	node = ht->shead;
	while (node)
	{
		printf("%s'%s': '%s'", comma, node->key, node->value);
		comma = ", ";
		node = node->snext;
	}
	puts("}");
}

/**
 * shash_table_print_rev - Print key/values of the sorted hashtable in reverse order
 * @ht: Hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *comma = "";

	if (!ht || !ht->array)
	{
		return;
	}

	putchar('{');
	node = ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'", comma, node->key, node->value);
		comma = ", ";
		node = node->sprev;
	}
	puts("}");
}

/**
 * shash_table_delete - Free and delete the sorted hash table
 * @ht: Hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int idx = 0;
	shash_node_t *node, *next;

	if (!ht)
	{
		return;
	}

	if (!(ht->array))
	{
		free(ht);
		return;
	}

	while (idx < ht->size)
	{
		node = (ht->array)[idx];
		while (node)
		{
			next = node->next;
			if (node->key)
				free(node->key);
			if (node->value)
				free(node->value);
			node->key = NULL;
			node->value = NULL;
			free(node);
			node = next;
		}
		idx++;
	}
	free(ht->array);
	free(ht);
}
