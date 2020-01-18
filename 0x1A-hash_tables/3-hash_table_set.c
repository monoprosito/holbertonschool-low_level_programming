#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
  * hash_table_set - Adds an element to the hash table
  * @ht: The hash table to add or update the key/value to
  * @key: The key of a value
  * @value: The value associated with the key
  *
  * Returns: 1 if it succeeded, 0 otherwise
  */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = 0;
	hash_node_t *elem = NULL, *new_node = NULL;

	if (ht == NULL || key == NULL)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	idx = key_index((unsigned char *) key, ht->size);
	elem = ht->array[idx];
	new_node->key = (char *) key;
	new_node->value = strdup(value);

	if (elem == NULL)
		new_node->next = NULL;
	else
		new_node->next = elem;

	elem = new_node;
	return (1);
}
