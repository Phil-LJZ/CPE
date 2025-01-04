#include <stdio.h>

int main(void){
    double array[8];
    double array2[8];
    double subtotal = 0;
    int i = 0;
    int a = 0;
    char temp;

    for (i = 0; i < 8; i++){
        // scanf("%f", &array[i]);
        array[i] = i;
    }

    for (int i1 = 0; i1 < 8; i1++){
        for (a = 0, subtotal = 0; a <= i1; a++){
            subtotal += array[a];
            array2[a] = subtotal;
        }
    }
    
    for (int i2 = 0; i2 < 8; i2++){
        printf("%.2f\n", array[i2]);
    }
    printf("\n");
    for (int i3 = 0; i3 < 8; i3++){
        printf("%.2f\n", array2[i3]);
    }

    return 0;
}