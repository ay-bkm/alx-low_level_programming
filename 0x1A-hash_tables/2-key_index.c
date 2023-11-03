#include "h_tables.h"

/**
 * key_index - Retrieves the index of a key in the hash table array
 * @key: Key to be hashed and indexed
 * @size: Size of the hash table array
 * Return: Index where the key/value pair is stored in the hash table array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idx;

	if (size == 0)
	{
		return (0);
	}

	idx = hash_djb2(key);
	return (idx % size);
}
