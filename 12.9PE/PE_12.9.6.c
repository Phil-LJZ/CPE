#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int t4 = 0;
    int t5 = 0;
    int t6 = 0;
    int t7 = 0;
    int t8 = 0;
    int t9 = 0;
    int t10 = 0;
    int r = rand() % 10;

    for(int i = 1; i <= 1000; i++)
    {
        srand(i);
        r = rand() % 10 + 1;
        switch (r)
        {
        case 1:
            t1++;
            break;
        case 2:
            t2++;
            break;
        case 3:
            t3++;
            break;
        case 4:
            t4++;
            break;
        case 5:
            t5++;
            break;
        case 6:
            t6++;
            break;
        case 7:
            t7++;
            break;
        case 8:
            t8++;
            break;
        case 9:
            t9++;
            break;
        case 10:
            t10++;
            break;
        
        default:
            break;
        }
    }
    printf(" 1 出现的次数为%.3d\n", t1);
    printf(" 2 出现的次数为%.3d\n", t2);
    printf(" 3 出现的次数为%.3d\n", t3);
    printf(" 4 出现的次数为%.3d\n", t4);
    printf(" 5 出现的次数为%.3d\n", t5);
    printf(" 6 出现的次数为%.3d\n", t6);
    printf(" 7 出现的次数为%.3d\n", t7);
    printf(" 8 出现的次数为%.3d\n", t8);
    printf(" 9 出现的次数为%.3d\n", t9);
    printf(" 10 出现的次数为%.3d\n", t10);

    return 0;
}