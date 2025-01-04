#include <stdio.h>

int main(void){
    float array[9];
    float subtoal = 1;
    int times = 8;
    int i1 = 0;

    for (int i = 0; i < times; i++){
        subtoal *=2;
    }
    for (int i = 0; i <= times; i++){
        array[i] = subtoal;
        subtoal /= 2;
    }

    do {
        printf("%f ", array[i1]);
        i1++;
    } while (i1 <= 8);

    return 0;
}