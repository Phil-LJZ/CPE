#include <stdio.h>
#include <float.h>

int main(void){
    double dn = 1.0/3.0;
    float fn = 1.0/3.0;

    printf("%-20s %-20s\n", "dn:", "fn:");
    printf("%-20.6f %-20.6f\n", dn, fn);
    printf("%-20.12f %-20.12f\n", dn, fn);
    printf("%-20.16f %-20.16f\n\n", dn, fn);
    printf("%-20s %-20s\n", "FLT_DIG:", "DBL_DIG:");
    printf("%-20.16f %-20.16f\n", FLT_DIG, DBL_DIG);

    return 0;
}