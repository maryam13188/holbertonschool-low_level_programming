#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *current, *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;  /* Save next pointer before freeing */
		free(current->str);    /* Free the duplicated string */
		free(current);         /* Free the node itself */
		current = next;        /* Move to next node */
	}
}
