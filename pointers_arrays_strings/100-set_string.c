#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: double pointer to set
 * @to: pointer to set the value to
 */
void set_string(char **s, char *to)
{
	*s = to;
}
