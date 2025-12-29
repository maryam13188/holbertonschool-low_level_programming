#include "main.h"
#include <stdlib.h>

/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
    while (*str)
        _putchar(*str++);
    _putchar('\n');
}

/**
 * _isdigit - checks if a string contains only digits
 * @str: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int _isdigit(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

/**
 * _strlen - returns length of string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

/**
 * multiply - multiplies two numbers
 * @num1: first number as string
 * @num2: second number as string
 */
void multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int *result;
    int i, j, carry, n1, n2, sum;
    
    result = malloc(sizeof(int) * (len1 + len2));
    if (!result)
        exit(98);
    
    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;
    
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';
        
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        
        if (carry > 0)
            result[i + j + 1] += carry;
    }
    
    i = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;
    
    if (i == len1 + len2)
        _putchar('0');
    else
        for (; i < len1 + len2; i++)
            _putchar(result[i] + '0');
    
    _putchar('\n');
    free(result);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        _puts("Error");
        exit(98);
    }
    
    if (!_isdigit(argv[1]) || !_isdigit(argv[2]))
    {
        _puts("Error");
        exit(98);
    }
    
    multiply(argv[1], argv[2]);
    
    return (0);
}
