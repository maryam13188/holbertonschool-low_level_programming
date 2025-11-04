#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to check
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - multiplies two positive numbers
 * @s1: first number
 * @s2: second number
 *
 * Return: pointer to result string
 */
char *multiply(char *s1, char *s2)
{
	int len1, len2, len, i, j, carry, digit1, digit2;
	char *result;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);

	/* Initialize result with zeros */
	for (i = 0; i < len; i++)
		result[i] = '0';
	result[len] = '\0';

	/* Multiply each digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = s1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += (result[i + j + 1] - '0') + (digit1 * digit2);
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}

		if (carry > 0)
			result[i + j + 1] = (carry % 10) + '0';
	}

	return (result);
}

/**
 * remove_leading_zeros - removes leading zeros from result
 * @s: string to process
 *
 * Return: pointer to processed string
 */
char *remove_leading_zeros(char *s)
{
	int i = 0;

	while (s[i] == '0' && s[i + 1] != '\0')
		i++;

	return (s + i);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	/* Check argument count */
	if (argc != 3)
		errors();

	/* Check if arguments are digits */
	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		errors();

	/* Multiply the numbers */
	result = multiply(num1, num2);
	if (result == NULL)
		errors();

	/* Remove leading zeros and print result */
	result = remove_leading_zeros(result);
	printf("%s\n", result);

	free(result);
	return (0);
}
