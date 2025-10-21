#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: input string
*
* Description: This function extracts the first number found in the string.
* It handles multiple '+' and '-' signs before the number.
* If there are no numbers in the string, it returns 0.
*
* Return: the integer value converted from the string
*/
int _atoi(char *s)
{
int i = 0, sign = 1, result = 0;


while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
else if (s[i] == '+')
;
else if (s[i] >= '0' && s[i] <= '9')
break;
i++;
}

while (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}

return (result * sign);
}

