#include "main.h"

/**
 * _sqrt_helper - helper function to find square root using binary search
 * @n: number to find square root of
 * @start: starting point for search
 * @end: ending point for search
 * Return: natural square root or -1 if not found
 */
int _sqrt_helper(int n, int start, int end)
{
	int mid;

	if (start > end)
		return (-1);

	mid = (start + end) / 2;

	if (mid * mid == n)
		return (mid);
	else if (mid * mid > n)
		return (_sqrt_helper(n, start, mid - 1));
	else
		return (_sqrt_helper(n, mid + 1, end));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root of
 * Return: natural square root or -1 if not found
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (_sqrt_helper(n, 1, n));
}
