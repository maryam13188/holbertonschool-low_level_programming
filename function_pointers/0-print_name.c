#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: function pointer that determines how to print the name
 *
 * Description: The function takes a name and a function pointer,
 *              then calls the function with the name as argument.
 */
#include "function_pointers.h"

void print_name(char *name, void (*f)(char *))
{
    if (name && f)
        f(name);
}
