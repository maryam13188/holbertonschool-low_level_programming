#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table
 * @ht: The hash table to add/update the key/value to
 * @key: The key (cannot be an empty string)
 * @value: The value associated with the key (must be duplicated)
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *current;
	unsigned long int index;
	char *value_copy;

	/* Check for NULL pointers and empty key */
	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	/* Create a copy of the value */
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	/* Get the index for the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			/* Key exists, update the value */
			free(current->value);
			current->value = value_copy;
			return (1);
		}
		current = current->next;
	}

	/* Create a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}

	/* Duplicate the key */
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		free(value_copy);
		return (0);
	}

	/* Set the node's values */
	new_node->value = value_copy;
	
	/* Add the new node at the beginning of the list */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
