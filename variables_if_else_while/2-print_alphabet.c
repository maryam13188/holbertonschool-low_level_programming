#include <stdio.h>

/**
 * main - prints the alphabet in lowercase
 *
 * Return: 0 always (Success)
 */
int main(void)
{
	char c; /* variable to store each letter */

	for (c = 'a'; c <= 'z'; c++) /* loop from 'a' to 'z' */
		putchar(c);               /* print the letter */

	putchar('\n');               /* print a new line at the end */

	return (0);
}
