#include "main.h"

/**
* puts2 - Prints every other character of a string,
*         starting with the first character.
* @str: The input string.
*
* Description:
* This function iterates through the string character by character.
* It prints only the characters whose index is even (0, 2, 4, ...).
* The odd-indexed characters are ignored using an else statement.
* After finishing, it prints a newline character.
*/
void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
if (i % 2 == 0)
{
_putchar(str[i]);
}
else
{

}
i++; 
}

_putchar('\n');
}

