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
			/* accumulate number safely */
			while (s[i] >= '0' && s[i] <= '9')
			{
				/* check potential overflow before multiplying */
				if (num > 214748364)
				{
					num = (sign == 1) ? 2147483647 : -2147483648;
					return (num);
				}
				else if (num == 214748364)
				{
					if ((s[i] - '0') > 7 && sign == 1)
						return (2147483647);
					if ((s[i] - '0') > 8 && sign == -1)
						return (-2147483648);
				}

				num = num * 10 + (s[i] - '0');
				i++;
			}
			break;
		}
		i++;
	}
	return (num * sign);
}
