#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in hash table
 * @ht: Hash table to add/update
 * @key: Key (cannot be empty)
 * @value: Value to associate with key
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *val;
	unsigned long int i;
	hash_node_t *tmp;

	if (!ht || !key || !*key || !value)
		return (0);

	val = strdup(value);
	if (!val)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[i];

	while (tmp)
	{
		if (!strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = val;
			return (1);
		}
		tmp = tmp->next;
	}

	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(val);
		return (0);
	}
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		free(val);
		return (0);
	}
	new->value = val;
	new->next = ht->array[i];
	ht->array[i] = new;
	return (1);
}
