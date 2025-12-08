#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table
 * @ht: The hash table to add/update the key/value to
 * @key: The key (cannot be an empty string)
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new, *tmp;
	unsigned long int idx;
	char *val_copy;

	if (!ht || !key || !*key || !value)
		return (0);

	val_copy = strdup(value);
	if (!val_copy)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	while (tmp)
	{
		if (!strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = val_copy;
			return (1);
		}
		tmp = tmp->next;
	}

	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(val_copy);
		return (0);
	}
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		free(val_copy);
		return (0);
	}
	new->value = val_copy;
	new->next = ht->array[idx];
	ht->array[idx] = new;

	return (1);
}
