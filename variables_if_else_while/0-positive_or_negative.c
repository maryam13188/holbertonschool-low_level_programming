#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - يخصص قيمة عشوائية للمتغير n ويطبع
 *        إذا كانت موجبة، صفر، أو سالبة
 *
 * Return: 0 عند النجاح
 */
int main(void)
{
    int n;

    /* توليد رقم عشوائي */
    srand(time(0));
    n = rand() - RAND_MAX / 2;

    if (n > 0)
    {
        printf("%d is positive\n", n);
    }
    else if (n == 0)
    {
        printf("%d is zero\n", n);
    }
    else
    {
        printf("%d is negative\n", n);
    }

    return (0);
}
