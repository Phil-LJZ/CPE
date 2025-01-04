#include <stdio.h>
#define hourly_wage 10.00
#define overtime_hours_multiple 1.50
#define tax_rate_300 0.15
#define tax_rate300_450 0.20
#define tax_rate450_ 0.25
#define m_basic_working_time 40

float calculate_total_salary(int);
float calculate_taxes(float);

int main(void){
    int working_hours;
    float taxes;
    float total_salary;
    float net_income;

    printf("请输入工作时长：");
    scanf("%d", &working_hours);

    total_salary = calculate_total_salary(working_hours);
    taxes = calculate_taxes(total_salary);
    net_income = total_salary - taxes;

    printf("总工资：%f\n税金：%f\n净收入：%f", total_salary, taxes, net_income);
    return 0;
}

float calculate_total_salary(int working_housrs){
    float total_salary;
    
    if (working_housrs <= m_basic_working_time){
        total_salary = working_housrs * hourly_wage;
    }
    else if (working_housrs > m_basic_working_time){
        working_housrs *= 1.5;
        total_salary = working_housrs * hourly_wage;
    }

    return 7 * total_salary;
}

float calculate_taxes(float total_salary){
    float taxes;

    if (total_salary <= 300){
        taxes = total_salary * tax_rate_300;
    }
    else if (total_salary > 300 && total_salary <= 450){
        taxes = 300 * tax_rate_300 + (total_salary -300) * tax_rate300_450;
    }
    else {
        taxes = 300 * tax_rate_300 + 150 * tax_rate300_450 + (total_salary - 450) * tax_rate450_;
    }

    return taxes;
}