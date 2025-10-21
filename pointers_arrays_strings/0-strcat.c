#include "main.h"

/**
 * _strcat - concatenates the string src to the end of dest
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    /* الوصول لنهاية dest */
    while (dest[i] != '\0')
        i++;

    /* نسخ محتويات src إلى نهاية dest */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* إضافة null byte في النهاية */
    dest[i] = '\0';

    return (dest);
}

