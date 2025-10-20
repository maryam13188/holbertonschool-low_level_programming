#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			break;
		}
		i++;
	}
	return (num * sign);
}
