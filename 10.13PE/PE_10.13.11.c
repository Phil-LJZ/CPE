#include <stdio.h>

void twice(int, int, int (*)[5]);
void print(int, int, int (*)[5]);

int main(void){
    int array[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    twice(3, 5, array);
    print(3, 5, array);

    return 0;
}

void twice(int size1, int size2, int (*array)[size2]){
    for (int a = 0; a < size1; a++){
        for (int i = 0; i < size2; i++){
            array[a][i] *= 2;
        }
    }
}
void print(int size1, int size2, int (*array)[size2]){
    for (int a = 0; a < size1; a++){
        for (int i = 0; i < size2; i++){
            printf("%d ", array[a][i]);
        }
        printf("\n");
    }
}