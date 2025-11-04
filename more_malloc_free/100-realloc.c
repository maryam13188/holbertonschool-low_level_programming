#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i, copy_size;
	char *char_ptr, *char_new_ptr;

	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));

	/* If new_size is 0 and ptr is not NULL, equivalent to free(ptr) */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If new_size == old_size, do nothing */
	if (new_size == old_size)
		return (ptr);

	/* Allocate new memory block */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Determine how much to copy - minimum of old and new sizes */
	copy_size = (old_size < new_size) ? old_size : new_size;

	/* Copy contents manually without memcpy */
	char_ptr = (char *)ptr;
	char_new_ptr = (char *)new_ptr;

	for (i = 0; i < copy_size; i++)
		char_new_ptr[i] = char_ptr[i];

	/* Free the old memory block */
	free(ptr);

	return (new_ptr);
}
