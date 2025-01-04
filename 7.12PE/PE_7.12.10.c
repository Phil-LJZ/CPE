#include <stdio.h>

#define taxable_income1 17850
// 单身应纳税收入
#define taxable_income2 23900
// 户主应纳税收入
#define taxable_income3 29750
// 已婚、共有应纳税收入
#define taxable_income4 14875
// 已婚、离异应纳税收入

float calculate_taxes(int, float);

int main(void){
    int category;
    float income;
    float taxes;

    printf("请输入类别、收入：");
    while ((scanf("%d %f", &category, &income)) == 2)
    {
        switch (category)
        {
        case 1:
            taxes = calculate_taxes(1, income);
            break;
        case 2:
            taxes = calculate_taxes(2, income);
            break;
        case 3:
            taxes = calculate_taxes(3, income);
            break;
        case 4:
            taxes = calculate_taxes(4, income);
            break;
        
        default:
            printf("请重新输入\n");
            printf("请输入类别、收入：");
            continue;
        }

        printf("税金为%f\n", taxes);
        printf("请输入类别、收入：");
    }

    return 0;
}

float calculate_taxes(int category, float income){
    float taxes = 0;

    switch (category)
    {
    case 1:
        if (income > taxable_income1)
        {
            taxes = taxable_income1 * 0.15 + (income - taxable_income1) * 0.28;
        }
        else if (income == taxable_income1)
        {
            taxes = taxable_income1 * 0.15;
        }
        else
        {
            break;
        }

        break;
    
    case 2:
        if (income > taxable_income2)
        {
            taxes = taxable_income2 * 0.15 + (income - taxable_income2) * 0.28;
        }
        else if (income == taxable_income2)
        {
            taxes = taxable_income2 * 0.15;
        }
        else
        {
            break;
        }
        
        break;

    case 3:
        if (income > taxable_income3)
        {
            taxes = taxable_income3 * 0.15 + (income - taxable_income3) * 0.28;
        }
        else if (income == taxable_income3)
        {
            taxes = taxable_income3 * 0.15;
        }
        else
        {
            break;
        }
        
        break;

    case 4:
        if (income > taxable_income4)
        {
            taxes = taxable_income4 * 0.15 + (income - taxable_income4) * 0.28;
        }
        else if (income == taxable_income4)
        {
            taxes = taxable_income4 * 0.15;
        }
        else
        {
            break;
        }
        
        break;
    
    default:
        break;
    }

    return taxes;
}