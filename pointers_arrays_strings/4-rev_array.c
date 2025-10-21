#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int start = 0;
	int end = n - 1;
	int temp;

	while (start < end)
	{
		/* Swap elements */
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;

		/* Move towards center */
		start++;
		end--;
	}
}
