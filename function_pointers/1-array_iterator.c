#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - executes a function on each element of an array
 * @array: array to iterate over
 * @size: size of the array
 * @action: function pointer to execute on each element
 *
 * Description: Applies the given function to every element in the array
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
