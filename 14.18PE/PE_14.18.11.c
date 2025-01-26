#include <stdio.h>
#include <math.h>

void transform(double *, double *, int, double (*) (double));
void show_array(double *, int);
double fun1(double num);
double fun2(double num);

int main(void)
{
    double array[100] = {
        45.67, 23.45, 78.90, 12.34, 56.78, 89.01, 34.56, 67.89, 23.46, 78.91,
        12.35, 56.79, 89.02, 34.57, 67.90, 23.47, 78.92, 12.36, 56.80, 89.03,
        34.58, 67.91, 23.48, 78.93, 12.37, 56.81, 89.04, 34.59, 67.92, 23.49,
        45.68, 23.50, 78.94, 12.38, 56.82, 89.05, 34.60, 67.93, 23.51, 78.95,
        12.39, 56.83, 89.06, 34.61, 67.94, 23.52, 78.96, 12.40, 56.84, 89.07,
        34.62, 67.95, 23.53, 78.97, 12.41, 56.85, 89.08, 34.63, 67.96, 23.54,
        45.69, 23.55, 78.98, 12.42, 56.86, 89.09, 34.64, 67.97, 23.56, 78.99,
        12.43, 56.87, 89.10, 34.65, 67.98, 23.57, 79.00, 12.44, 56.88, 89.11
    };

    double test_array[100];

    printf("第1组(求平方根):\n");
    transform(array, test_array, 100, sqrt);
    show_array(test_array, 100);
    printf("第2组(取整):\n");
    transform(array, test_array, 100, trunc);
    show_array(test_array, 100);
    printf("第3组(加10):\n");
    transform(array, test_array, 100, fun1);
    show_array(test_array, 100);
    printf("第4组(乘10):\n");
    transform(array, test_array, 100, fun2);
    show_array(test_array, 100);

    return 0;
}

void show_array(double * array, int size)
{
    int index;

    for (index = 0; index < size - 1; index++)
    {
        if (index % 7 == 0 && index != 0)
        {
            fprintf(stdout, "%.3f\n", array[index]);
        }
        fprintf(stdout, "%.3f, ", array[index]);
    }
    fprintf(stdout, "%.3f\n", array[index+1]);
}
void transform(double * source, double * target, int size, double (*fun)(double))
{
    for (int i = 0; i < size; i++)
    {
        target[i] = fun(source[i]);
    }
}
double fun1(double num)
{
    return num + 10.0L;
}
double fun2(double num)
{
    return num * 10.0L;
}