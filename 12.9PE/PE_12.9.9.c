#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char * array1;
    char * array2;
    char ch;
    int count = 0;

    while ((ch = getchar()) != '\n')
    {
        count++;
        array1 = (char *) malloc(count * sizeof(char));
        *(array1 + count - 1) = ch;
    }
    
    // TODO
}