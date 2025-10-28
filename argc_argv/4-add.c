#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	/* If no numbers passed, print 0 */
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	/* Check each argument */
	for (i = 1; i < argc; i++)
	{
		/* Check if each character in the argument is a digit */
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		/* Convert to integer and add to sum */
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
