#include <stdio.h>
#include <string.h>

#define SIZE 8

int main(void){
    int array[SIZE];
    int index;

    printf("请输入八个整数：");

    for (index = 0; index < SIZE; index++){
        scanf("%d", &array[index]);
    }
    for (index = SIZE - 1; index >= 0; index--){
        printf("%d ", array[index]);
    }

    return 0; 
}