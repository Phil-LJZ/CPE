#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(void)
{
    int array[100];

    for(int i = 0; i < 100; i++)
    {
        *(array + i) = rand() % 100 + 1;
    }
    print_array(array, 100, 0);
    sort(array, 100);
    print_array(array, 100, 1);

    return 0;
}