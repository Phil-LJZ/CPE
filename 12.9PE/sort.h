#include <stdbool.h>
#include <stdio.h>

void print_array(int * array, int size, int index)
{
    printf("(%.2d)  {", index);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[size - 1]);
}

void sort(int * array, int size)
{
    // 降序排序函数

    int p;
    bool sorting_completed = false;
    int sorted_number = 0;
    int index = 0;
    // int count = 0;

    while (!sorting_completed)
    {
        if (size > 1)
        {
            for(index = 0, sorted_number = 0; index < size - 1; index++)
            {
                if (array[index] < array[index + 1])
                {
                    p = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = p;
                }
                if (array[size - 1 - index - 1] < array[size - 1 - index])
                {
                    sorted_number--;
                }
                else
                {
                    sorted_number++;
                }
                if (sorted_number == (size - 1))
                {
                    sorting_completed = true;
                }
            }
        }
        else
        {
            sorting_completed = true;
        }
        // print_array(array, size, count);
        // count++;
    }
}