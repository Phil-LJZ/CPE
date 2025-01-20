#include <stdio.h>
#define SIZE 13

void sort(int *, int);
void reverse(int *, int);

int main(void){
    int array[SIZE] = {237, 4, 9, 8, 890, 1, 2, 5, 6, 3, 7, 10, 110};

    sort(array, SIZE);
    for (int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }

    printf("\n");

    reverse(array, SIZE);
    for (int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }

    return 0;
}

void sort(int *array, int size){
    int temp = 0;
    int times = 0;
    for (times; times < size; times++){
        for (int i = 0; i < size; i++){
            if (array[i] < array[i+1] && i < size - 1){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    printf("%d\n", times - 1);
}
void reverse(int *array, int size){
    int temp = 0;
    int times = 0;
    for (times; times < size; times++){
        for (int i = 0; i < size; i++){
            if (array[i] > array[i+1] && i < size - 1){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    printf("%d\n", times - 1);
}