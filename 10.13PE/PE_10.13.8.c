#include <stdio.h>

void copy_ptr(double *, double *, int);

int main(void){
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target[3];

    copy_ptr(target, source + 2, 3);
    printf("Target:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%f\n", target[i]);
    }

    return 0;
}
void copy_ptr(double target[], double source[], int size){
    for (int i = 0; i < 5; i++){
        *(target + i) = *(source + i);
    }
}