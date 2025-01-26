#include <stdio.h>

int compute(char *);

int main(void)
{
    char * stirng = "0101000101101";
    printf("%d", compute(stirng));

    return 0;
}

int compute(char * string)
{
    int size = 0;
    int index;
    int total = 0;
    int temp = 1;

    while (string[size] != '\0')
    {
        size++;
    }
    for (index = 0; index < size; index++, temp = 1)
    {
        if ((string[index] - 48) == 0)
        {
            continue;
        }
        for (int c = 0; c < (size - index - 1); c++)
        {
            temp *= 2;
        }
        temp *= (string[index] - 48);
        total += temp;
    }

    return total;
}