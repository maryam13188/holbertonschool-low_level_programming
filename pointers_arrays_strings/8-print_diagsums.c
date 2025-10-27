#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the matrix (1D array representation)
 * @size: size of the square matrix
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0, sum2 = 0;

	/* Calculate main diagonal (top-left to bottom-right) */
	for (i = 0; i < size; i++)
		sum1 += a[i * size + i];

	/* Calculate secondary diagonal (top-right to bottom-left) */
	for (i = 0; i < size; i++)
		sum2 += a[i * size + (size - 1 - i)];

	printf("%d, %d\n", sum1, sum2);
}
