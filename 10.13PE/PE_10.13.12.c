#include <stdio.h>
#define SIZE 10
void copy_arr(int size1, int size2, double (*)[size1], double (*)[size2]);
void print_arr(int size1, int size2, double (*)[size1]);
int main(void){
    double source[10][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 12},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 13},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 11}
    };
    double target[10][10];

    copy_arr(SIZE, SIZE, target, source);
    print_arr(SIZE, SIZE, target);

    return 0;
}

void copy_arr(int size1, int size2, double (*target)[size1], double (*source)[size2]){
    for (int a = 0; a < size1; a++){
        for (int b = 0; b < size2; b++){
            target[a][b] = source[a][b];
        }
    }
}
void print_arr(int size1, int size2, double (*target)[size1]){
    for (int a = 0; a < size1; a++){
        printf("{");
        for (int b = 0; b < size2 - 1; b++){
            printf("%.f, ", target[a][b]);
        }
        printf("%.f", target[a][size2 - 1]);
        printf("}\n");
    }
}