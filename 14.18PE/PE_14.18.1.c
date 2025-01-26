#include <stdio.h>
#include <string.h>

struct mon_inf
{
    char month_name[10]; // 月份名
    char month_abb[3]; // 月份名缩写
    char month_days; // 月份的天数
    char month_spelling[10]; // 月份的拼写
};

void mygets(char *, int, FILE *);

int main(void)
{
    struct mon_inf m_array[12] = {
        {
            "January",
            "Jan",
            31,
            "yiyue"
        },
        {
            "February",
            "Feb",
            28,
            "eryue"
        },
        {
            "March",
            "Mar",
            31,
            "sanyue"
        },
        {
            "April",
            "Apr",
            30,
            "siyue"
        },
        {
            "May",
            "May",
            31,
            "wuyue"
        },
        {
            "June",
            "Jun",
            30,
            "liuyue"
        },
        {
            "July",
            "Jul",
            31,
            "qiyue"
        },
        {
            "August",
            "Aug",
            31,
            "bayue"
        },
        {
            "September",
            "Sep",
            30,
            "yiyue"
        },
        {
            "October",
            "Oct",
            31,
            "shiyue"
        },
        {
            "November",
            "Nov",
            30,
            "shiyiyue"
        },
        {
            "December",
            "Dec",
            31,
            "shieryue"
        }
    };
    char temp[11];
    char ch;
    char count = 0;
    int index;
    int total = 0;

    printf("请输入月份拼写：");
    mygets(temp, 11, stdin);
    for (index = 0; index < 12; index++)
    {
        if (strcmp(temp, (m_array+index)->month_spelling) == 0)
        {
            total += (m_array+index)->month_days;
            break;
        }
        total += (m_array+index)->month_days;
    }
    printf("1月到%d月的所有天数总和为%d天", index+1, total);

    return 0;
}
void mygets(char * string, int size, FILE * fp)
{
    char temp;
    int count = 0;

    while ((temp = getc(fp)) != '\n')
    {
        if (count > size - 1)
        {
            while (getc(fp) != '\n')
            {
                continue;
            }
            string[size - 1] = '\0';
            break;
        }
        string[count] = temp;
        count++;
    }
}