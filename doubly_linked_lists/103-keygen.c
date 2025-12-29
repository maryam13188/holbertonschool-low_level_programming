#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* تعريف جميع المتغيرات أولاً */
    unsigned int hash = 0x1505;
    char *s;
    int i;
    
    if (argc != 2)
    {
        printf("Usage: %s username\n", argv[0]);
        return (1);
    }
    
    s = argv[1];
    
    while (*s)
    {
        hash = (hash << 5) + hash + *s;
        s++;
    }
    
    printf("%u\n", hash);
    
    return (0);
}
