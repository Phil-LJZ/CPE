#include <stdio.h>

int atoi1(char *);

int main(void)
{
    printf("%d", atoi1("5890432"));

    return 0;
}

int atoi1(char * string)
{
    char * p = string;
    int size = 0;
    int temp = 1;
    int total = 0;
    
    for(; *p != '\0'; p++, size++)
    {
        ;
    }
    p = string;
    for(int a = 0; a < size; a++)
    {
        for(int b = 0; b < (size - a - 1); b++)
        {
            temp *= 10;
        }
        total += (p[a] - 48) * temp;
        temp = 1;
    }

    return total;
}