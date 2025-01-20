#include <stdio.h>

void copy_arr(int size1, int size2, double (*)[size2], double (*)[size2]);
void print_arr(int size1, int size2, double (*)[size2], double (*)[size2]);

int main(void){
    int size1 = 5;
    int size2 = 3;

    double source[5][3] = {
        {8, 9, 10},
        {4, 5, 6},
        {1, 2, 3},
        {7, 8, 9},
        {1, 4, 8}
    };
    double target[5][3];

    copy_arr(size1, size2, target, source);
    print_arr(size1, size2, target, source);

    return 0;
}
void copy_arr(int size1, int size2, double (*target)[size2], double (*source)[size2]){
    for (int a = 0; a < size1; a++){
        for (int b = 0; b < size2; b++){
            target[a][b] = source[a][b];
        }
    }
}
void print_arr(int size1, int size2, double (*target)[size2], double (*source)[size2]){
    for (int a = 0; a < size1; a++){
        printf("{");
        for (int b = 0; b < size2 - 1; b++){
            printf("%.f, ", target[a][b]);
        }
        printf("%.f", target[a][size2 - 1]);
        printf("}\n");
    }
}