#include "main.h"

/**
 * print_triangle - prints a right-aligned triangle of size 'size'
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* print spaces */
		for (j = 1; j <= size - i; j++)
			_putchar(' ');
		/* print #'s */
		for (j = 1; j <= i; j++)
			_putchar('#');
		_putchar('\n');
	}
}
