#include <stdio.h>

void array_fusion(int *, int *, int *, int);

int main(void){
    int array1[4] = {2, 4, 5, 8};
    int array2[4] = {1, 0, 4, 6};
    int target[4];
    
    array_fusion(array1, array2, target, 4);

    for (int i = 0; i < 4; i++){
        printf("%d\n", target[i]);
    }
}

void array_fusion(int *array1, int *array2, int *target, int size){
    int temp = 0;
    for (int a = 0; a < size; a++){
        target[a] = array1[a] + array2[a];
    }
}