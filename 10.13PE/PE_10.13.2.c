#include <stdio.h>

void copy_arr(double *, double *, int);
void copy_ptr(double *, double *, int);
void copy_ptrs(double *, double *, double *);

int main(void){
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source+5);

    printf("Target1:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", target1[i]);
    }
    printf("Target2:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", target2[i]);
    }
    printf("Target3:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", target3[i]);
    }
}

void copy_arr(double target[], double source[], int size){
    for (int i = 0; i < 5; i++){
        target[i] = source[i];
    }
}
void copy_ptr(double target[], double source[], int size){
    for (int i = 0; i < 5; i++){
        *(target + i) = *(source + i);
    }
}
void copy_ptrs(double target[], double source[], double *source_p){
    int i = 0;
    while ((source + i) < source_p)
    {
        target[i] = *(source + i);
        i++;
    }
}