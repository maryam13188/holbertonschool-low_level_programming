#include "main.h"

/**
 * puts_half - prints half of a string followed by a new line
 * @str: input string
 */
void puts_half(char *str)
{
    int len = 0, i;

    /* calculate the length of the string */
    while (str[len] != '\0')
        len++;

    /* determine the starting index of the second half */
    i = (len % 2 == 0) ? (len / 2) : ((len + 1) / 2);

    /* print characters from the middle to the end */
    while (i < len)
    {
        _putchar(str[i]);
        i++;
    }

    _putchar('\n');
}
