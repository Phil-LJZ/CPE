#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct bpp_inf {
    int serial_num; // 球员号
    char last_name[10];
    char first_name[10];
    int appearances;
    int hits;
    int strokes;
    int RPI;
    float ba; // 安打率
};

void output(struct bpp_inf, FILE *);
struct bpp_inf * add_struct(struct bpp_inf *, struct bpp_inf *, int);
void copy_array(struct bpp_inf *, struct bpp_inf *, int);
int readline(struct bpp_inf *, FILE *);
int compar(const void *, const void *);
int remove_duplicates(struct bpp_inf *, int);
struct bpp_inf * merge_duplicates(struct bpp_inf *, int *);

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码

    struct bpp_inf temp;
    int count = 0;
    int index;
    FILE * fp;
    struct bpp_inf * bf_array;

    if ((bf_array = (struct bpp_inf *) malloc(sizeof(struct bpp_inf))) == NULL)
    {
        fprintf(stderr, "初始化结构数组失败");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen("BPP_data.txt", "r")) == NULL)
    {
        fprintf(stderr, "打开文件错误");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    while (readline(&temp, fp) != EOF)
    {
        count++;
        bf_array = add_struct(bf_array, &temp, count);
    }
    for (index = 0; index < count; index++)
    {
        output(bf_array[index], stdout);
    }
    qsort(bf_array, count, sizeof(struct bpp_inf), compar);
    fprintf(stdout, "排序之后:\n");
    for (index = 0; index < count; index++)
    {
        output(bf_array[index], stdout);
    }
    bf_array = merge_duplicates(bf_array, &count);
    fprintf(stdout, "合并重复项之后：\n");
    for (index = 0; index < count; index++)
    {
        output(bf_array[index], stdout);
    }
    // 计算安打率
    for (index = 0; index < count; index++)
    {
        bf_array[index].ba = (float) bf_array[index].hits / (float) bf_array[index].appearances;
    }
    fprintf(stdout, "计算完安打率之后：\n");
    for (index = 0; index < count; index++)
    {
        output(bf_array[index], stdout);
    }

    free(bf_array);

    return 0;
}
struct bpp_inf * add_struct(struct bpp_inf * array, struct bpp_inf * bf, int size)
{
    // size 是 array 的大小
    struct bpp_inf * new_array;

    array[size - 1] = *bf; 
    if ((new_array = (struct bpp_inf *) malloc((size + 1) * sizeof(struct bpp_inf))) == NULL)
    {
        fprintf(stderr, "为添加新结构创建新结构数组失败");
        free(array);
        exit(EXIT_FAILURE);
    }
    copy_array(array, new_array, size);
    free(array);
    return new_array;
}
void copy_array(struct bpp_inf * source_array, struct bpp_inf * target_array, int size)
{
    int index;
    
    for (index = 0; index < size; index++)
    {
        target_array[index] = source_array[index];
    }
}
void output(struct bpp_inf bf, FILE * fp)
{
    fprintf(
        fp, "%d %s %s %d %d %d %d %f\n",
        bf.serial_num,
        bf.last_name,
        bf.first_name,
        bf.appearances,
        bf.hits,
        bf.strokes,
        bf.RPI,
        bf.ba
        );
}
int readline(struct bpp_inf * bf, FILE * fp)
{
    if (fscanf(
        fp, "%d %s %s %d %d %d %d",
        &(bf->serial_num),
        &(bf->last_name),
        &(bf->first_name),
        &(bf->appearances),
        &(bf->hits),
        &(bf->strokes),
        &(bf->RPI)
    ) != 7)
    return EOF;

    bf->ba = 0;
    return 1;
}
int compar(const void * p1, const void * p2)
{
    struct bpp_inf * a1 = (struct bpp_inf *) p1;
    struct bpp_inf * a2 = (struct bpp_inf *) p2;

    if (strcmp(a1->last_name, a2->last_name) == 0)
    {
        return 0;
    }
    else if (strcmp(a1->last_name, a2->last_name) < 1)
    {
        return -1;
    }
    else if (strcmp(a1->last_name, a2->last_name) > 1)
    {
        return 1;
    }
}
struct bpp_inf * merge_duplicates(struct bpp_inf * bf_array, int * size)
{
    int repeat = 1;
    int index = 1;
    struct bpp_inf * new_array;

    while (index < *size)
    {
        if (strcmp(bf_array[index].last_name, bf_array[index - 1].last_name))
        {
            bf_array[repeat] = bf_array[index];
            repeat++;
        }
        bf_array[index - 1].appearances += bf_array[index].appearances;
        bf_array[index - 1].hits += bf_array[index].hits;
        bf_array[index - 1].strokes += bf_array[index].strokes;
        bf_array[index - 1].RPI += bf_array[index].RPI;
        index++;
    }

    if (repeat < *size)
    {
        if ((new_array = (struct bpp_inf *) malloc(repeat * sizeof(struct bpp_inf))) == NULL)
        {
            fprintf(stderr, "为添加新结构创建新结构数组失败");
            free(bf_array);
            exit(EXIT_FAILURE);
        }
        copy_array(bf_array, new_array, repeat);
        free(bf_array);
    }

    *size = repeat;
    return new_array;
}