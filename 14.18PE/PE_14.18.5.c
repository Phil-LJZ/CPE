#include <stdio.h>
#include <string.h>
#include <windows.h>

#define CSIZE 4

struct name
{
    char last_name[10];
    char first_name[10];
};
struct student
{
    struct name student_name;
    float score[4];
};

void my_gets(char *, int, FILE *);
void my_scanf(float *, FILE *);
void my_cat(char *, char *);
void get_student_inf(struct student *);
void output_s_inf(struct student *);

int main(void)
{
    int index;
    char first_name[10];
    char second_name[10];
    struct student s_student[CSIZE];
    
    for (index = 0; index < CSIZE; index++)
    {
        get_student_inf(s_student + index);
    }
    for (index = 0; index < CSIZE; index++)
    {
        output_s_inf(s_student + index);
    }

    return 0;
}
void my_gets(char * string, int size, FILE * fp)
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
void my_scanf(float * num, FILE * fp)
{
    fscanf(fp, "%f", num);
    while (getc(stdin) != '\n')
    {
        ;
    }
}
void get_student_inf(struct student * s_inf)
{
    char first_name[10];
    char last_name[10];
    int index;
    float score = 0; // 暂时记录分数
    float total = 0;
    float a_score = 0; // 平均分

    fprintf(stdout, "请输入你的姓：");
    my_gets(first_name, 10, stdin);
    strncpy(s_inf->student_name.first_name, first_name, 10);
    fprintf(stdout, "请输入你的名：");
    my_gets(last_name, 10, stdin);
    strncpy(s_inf->student_name.last_name, last_name, 10);

    for (index = 0; index < 3; index++)
    {
        fprintf(stdout, "请输入成绩：");
        my_scanf(&score, stdin);
        total += score;
        s_inf->score[index] = score;
    }
    a_score = total / 3.0;
    s_inf->score[3] = a_score;
    printf("平均分:%f\n", s_inf->score[3]);
}
void output_s_inf(struct student * s_inf)
{
    fprintf(
        stdout, "%s %s 的三次成绩分别是 %2.f %2.f %2.f, 平均分是 %f\n",
        s_inf->student_name.last_name,
        s_inf->student_name.first_name,
        s_inf->score[0],
        s_inf->score[1],
        s_inf->score[2],
        s_inf->score[3]
    );
}