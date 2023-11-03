#ifndef _HASH_TABLES_
#define _HASH_TABLES_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct hash_node_s - Node structure for a hash table
 *
 * @key: The key, represented as a string
 * The key must be unique within the HashTable
 * @value: The corresponding value for a given key
 * @next: A pointer to the next node in the list
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Data structure for a hash table
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * used for Chaining collision handling in the HashTable
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/* Function prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/* Structures and function prototypes for 100-sorted_hash_table.c */
/**
 * struct shash_node_s - Node structure for a sorted hash table
 *
 * @key: The key, represented as a string
 * The key must be unique in the HashTable
 * @value: The corresponding value for a given key
 * @next: A pointer to the next node in the list
 * @sprev: A pointer to the previous element in the sorted linked list
 * @snext: A pointer to the next element in the sorted linked list
 */
typedef struct shash_node_s
{
    char *key;
    char *value;
    struct shash_node_s *next;
    struct shash_node_s *sprev;
    struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Data structure for a sorted hash table
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * used for Chaining collision handling in the HashTable
 * @shead: A pointer to the first element in the sorted linked list
 * @stail: A pointer to the last element in the sorted linked list
 */
typedef struct shash_table_s
{
    unsigned long int size;
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif /* End of HASH_TABLES file */
