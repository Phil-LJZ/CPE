#include <stdio.h>

float get_numbers(void);
float get_options(void);

int main(void){
    char options;
    float num1 = 0;
    float num2 = 0;
    float result = 0;

    printf("Enter the operation of your choice:\n"
            "a. add s. subtract\n"
            "m. multiply d. divide\n"
            "q. quit\n");
    while ( (options = get_options()) != 'q')
    {
        printf("Enter first number:");
        num1 = get_numbers();
        printf("Enter second number:");
        while ( (num2 = get_numbers()) <= 0)
        {
            printf("enter a number other than 0:");
        }
        switch (options)
        {
        case 'a':
            result = num1 + num2;
            printf("%f + %f = %f\n", num1, num2, result);
            break;
        case 's':
            result = num1 - num2;
            printf("%f - %f = %f\n", num1, num2, result);
            break;
        case 'm':
            result = num1 * num2;
            printf("%f * %f = %f\n", num1, num2, result);
            break;
        case 'd':
            result = num1 / num2;
            printf("%f / %f = %f\n", num1, num2, result);
            break;
        
        default:
            printf("Enter the operation of your choice:\n"
                    "a. add s. subtract\n"
                    "m. multiply d. divide\n"
                    "q. quit\n");
            break;
        }
        printf("\n");
        printf("Enter the operation of your choice:\n"
                "a. add s. subtract\n"
                "m. multiply d. divide\n"
                "q. quit\n");
    }

    return 0;   
}

float get_numbers(void){
    float input;
    char ch;
    
    while ((scanf("%f", &input)) != 1){
        while ((ch = getchar()) != '\n')
        {
            continue;
        }
        printf("Please enter a number, such as 2.5, -1.78E8, or 3.1\n");
    }
    while ((ch = getchar()) != '\n')
    {
        continue;
    }
    
    return input;
}
float get_options(void){
    char ch;
    char ch1;

    ch = getchar();

    while ((ch1 = getchar()) != '\n')
    {
        continue;
    }
    
    return ch;
}