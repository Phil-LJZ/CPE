#include <stdio.h>

int main(void){
    int array[100];
    int count = 0;
    int even_sum = 0;
    int even_number = 0;
    int odd_sum = 0;
    int odd_number = 0;

    printf("请输入整数：");
    while (scanf("%d", &array[count]) == 1 && count < 100 && array[count] != 0)
    {
        count++;
    }
    
    for (int i = 0; i <= count; i++){
        printf(" %d\n", array[i]);
       if (array[i] % 2 == 0 && array[i] != 0){
        even_sum+=array[i];
        even_number++;
       }
       else if (array[i] % 2 == 1){
        odd_sum+=array[i];
        odd_number++;
       }
    }

    printf("偶数个数：%d\n", even_number);
    printf("偶数平均值：%f\n", ((float) even_sum) / ((float) even_number));
    printf("奇数个数：%d\n", odd_number);
    printf("奇数平均值：%f\n", ((float) odd_sum) / ((float) odd_number));
}