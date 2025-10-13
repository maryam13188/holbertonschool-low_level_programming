#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, then uppercase
 *
 * Return: 0 always (Success)
 */
int main(void)
{
	char c; /* variable to store each letter */

	/* print lowercase letters from 'a' to 'z' */
	for (c = 'a'; c <= 'z'; c++)
		putchar(c);

	/* print uppercase letters from 'A' to 'Z' */
	for (c = 'A'; c <= 'Z'; c++)
		putchar(c);

	/* print newline at the end */
	putchar('\n');

	return (0);
}
