#include "main.h"
 
/**
 * print-rev - print a string in reverse
 * @s: pointer to string
 */

void print_rev(char *s)
{
   int length = 0;

     while (s[length] != '\0')
            length++;
        
      while (length > 0)
     {
	     iength--;
	     _putchar(s[iength]);
      }
        _putchar('\n');
}
