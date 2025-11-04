#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);  /* ← أضف هذا السطر */
int is_digit(char *s);
int _strlen(char *s);
void errors(void);

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    char *s1, *s2;
    int len1, len2, len, i, carry, n1, n2, *result, a = 0;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        errors();
    s1 = argv[1], s2 = argv[2];
    len1 = _strlen(s1);
    len2 = _strlen(s2);
    len = len1 + len2;
    result = calloc(len, sizeof(int));
    if (result == NULL)
        return (1);
    for (len1 -= 1; len1 >= 0; len1--)
    {
        n1 = s1[len1] - '0';
        carry = 0;
        for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
        {
            n2 = s2[len2] - '0';
            carry += result[len1 + len2 + 1] + (n1 * n2);
            result[len1 + len2 + 1] = carry % 10;
            carry /= 10;
        }
        if (carry > 0)
            result[len1 + len2 + 1] += carry;
    }
    for (i = 0; i < len; i++)
    {
        if (result[i])
            a = 1;
        if (a)
            _putchar(result[i] + '0');
    }
    if (!a)
        _putchar('0');
    _putchar('\n');
    free(result);
    return (0);
}

/**
 * is_digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if all digits, else 0
 */
int is_digit(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - returns string length
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

/**
 * errors - prints error and exits
 */
void errors(void)
{
    printf("Error\n");
    exit(98);
}

