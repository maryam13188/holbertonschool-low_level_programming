#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) return 1;
    
    unsigned int hash = 0x1505;
    char *s = argv[1];
    
    while (*s)
        hash = (hash << 5) + hash + *s++;
    
    printf("%u\n", hash);
    
    return 0;
}
