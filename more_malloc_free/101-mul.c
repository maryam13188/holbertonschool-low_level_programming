#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* الدوال المساعدة السابقة تبقى كما هي */

/**
 * multiply - multiplies two positive numbers (improved version)
 * @s1: first number
 * @s2: second number
 *
 * Return: pointer to result string
 */
char *multiply(char *s1, char *s2)
{
	int len1, len2, len, i, j, carry, digit1, digit2, temp;
	char *result;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2;
	
	result = calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);

	/* Initialize with zeros (calloc already does this) */
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
			temp = (result[i + j + 1] - '0') + (digit1 * digit2) + carry;
			result[i + j + 1] = (temp % 10) + '0';
			carry = temp / 10;
		}

		/* Handle remaining carry */
		while (carry > 0)
		{
			temp = (result[i + j + 1] - '0') + carry;
			result[i + j + 1] = (temp % 10) + '0';
			carry = temp / 10;
			j--;
		}
	}

	return (result);
}
