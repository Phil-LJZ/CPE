#include <stdio.h>
#include <string.h>
#include <windows.h>

struct mon_inf
{
    char month_name[11]; // 月份名
    char month_abb[4]; // 月份名缩写
    char month_days; // 月份的天数
    char month_spelling[11]; // 月份的拼写
};

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

void mygets(char *, int, FILE *);
void myscanf(int *, FILE *);
int compute_days(struct mon_inf *, int, int);

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    
    int year = 0;
    char month_name[11];
    int days = 0;
    int total_days = 0;
    int index;

    fprintf(stdout, "请输入年：");
    myscanf(&year, stdin);
    fprintf(stdout, "请输入月份：");
    mygets(month_name, 11, stdin);
    fprintf(stdout, "请输入天数：");
    myscanf(&days, stdin);

    for (index = 0; index < 12; index++)
    {
        if (strcmp(month_name, (m_array+index)->month_name) == 0)
        {
            total_days = compute_days(m_array, index, days);
            break;
        }
        else if (strcmp(month_name, (m_array+index)->month_abb) == 0)
        {
            total_days = compute_days(m_array, index, days);
            break;
        }
        else if (strcmp(month_name, (m_array+index)->month_spelling) == 0)
        {
            total_days = compute_days(m_array, index, days);
            break;
        }
    }

    fprintf(stdout, "总天数为：%d", total_days);

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
    string[count] = '\0';
}
void myscanf(int * num, FILE * fp)
{
    fscanf(fp, "%d", num);
    while (getc(stdin) != '\n')
    {
        ;
    }
}
int compute_days(struct mon_inf * array, int month, int days)
{
    int index;
    int total;

    for (index = 0, total = 0; index < month - 1; index++)
    {
        total += (array+index)->month_days;
    }
    total += days;

    return total;
}