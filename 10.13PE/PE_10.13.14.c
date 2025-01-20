#include <stdio.h>
#define SIZE1 3
#define SIZE2 5

void print_arr(int, int, float (*)[]);
float array_av(float *, int);
float array_av_2(int, int, float (*)[]);
float max(float *, int);
float max_array(int, int, float (*)[]);

int main(void){
    float array[SIZE1][SIZE2];

    for (int a = 0; a < 3; a++){
        printf("请输入 %d 个数字（用空格空开）：", SIZE2);
        for (int i = 0; i < 5; i++){
            scanf("%f", &(array[a][i]));
        }
    }

    printf("数组内容：\n");
    print_arr(SIZE1, SIZE2, array);
    for (int i = 0; i < 3; i++){
        printf("子数组 %d 的平均值：%f\n", i+1, array_av(array[i], SIZE2));
    }
    printf("所有数据的平均值：%f\n", array_av_2(SIZE1, SIZE2, array));
    printf("所有数据的最大值：%f", max_array(SIZE1, SIZE2, array));

    return 0;
}

void print_arr(int size1, int size2, float (*target)[size2]){
    // 打印一个二维数组

    for (int a = 0; a < size1; a++){
        printf("{");
        for (int b = 0; b < size2 - 1; b++){
            printf("%.f, ", target[a][b]);
        }
        printf("%.f", target[a][size2 - 1]);
        printf("}\n");
    }
}
float array_av(float *array, int size){
    // 计算一个数组的平均值

    float average_value;

    for (int i = 0; i < size; i++){
        average_value += array[i];
    }

    return average_value / size;
}
float array_av_2(int size1, int size2, float (*target)[size2]){
    int size = size1 * size2;
    float total;

    for (int i = 0; i < size1; i++){
        for (int a = 0; a < size2; a++){
            total += target[i][a];
        }
    }

    return total / size;
}
float max(float *array, int size){
    // 获得一个数组的最大值

    float temp = 0;
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

    return array[0];
}
float max_array(int size1, int size2, float (*target)[size2]){
    // 获取一个二维数组的最大值

    float array[size1];

    for (int a = 0; a < size1; a++){
        array[a] = max(target[a], size2);
    }

    return max(array, size1);
}