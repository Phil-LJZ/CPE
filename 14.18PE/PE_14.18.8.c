#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define MAXCHARS 10
#define MAXSEAT 12

struct seat_inf {
    int seat_number;
    bool is_book;
    char last_name[MAXCHARS];
    char first_name[MAXCHARS];
};
size_t seat_inf_size = sizeof(struct seat_inf);

void show_options(void);
char get_options(FILE *);
void my_gets(char *, int, FILE *);
int compar(const void *, const void *);
void show_sorted_sf_array(struct seat_inf *, int);
void show_empty_seat(struct seat_inf *, int);
int compute_empty_seat(struct seat_inf *, int);
void show_seat(struct seat_inf *, int);
void set_seat_inf(struct seat_inf *, int);
int get_seat_number(FILE *);
void delete_seat_inf(struct seat_inf *, int);

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码

    char ch;
    int vacant_seats = 0;
    int seat_number = 0;
    struct seat_inf sf_array[MAXSEAT] = {
        {1, true, "Smith", "John"},      // 已预订
        {2, false, "", ""},               // 未预订
        {3, true, "Brown", "Charlie"},    // 已预订
        {4, false, "", ""},                // 未预订
        {5, true, "Williams", "Michael"},  // 已预订
        {6, false, "", ""},                // 未预订
        {7, true, "Garcia", "David"},      // 已预订
        {8, false, "", ""},                // 未预订
        {9, true, "Davis", "James"},       // 已预订
        {10, false, "", ""},               // 未预订
        {11, true, "Wilson", "Robert"},    // 已预订
        {12, false, "", ""}                // 未预订
    };

    show_options();
    fprintf(stdout, "请输入选项：");
    while ((ch = get_options(stdin)) != 'f')
    {
        switch (ch)
        {
        case 'a':
            vacant_seats = compute_empty_seat(sf_array, MAXSEAT);
            fprintf(stdout, "空座位的数量为：%d\n", vacant_seats);
            break;
        case 'b':
            for(int i = 0; i < MAXSEAT; i++)
            {
                if (!(sf_array[i].is_book))
                {
                    fprintf(stdout, "%d 号座位是空的\n", sf_array[i].seat_number);
                }
            }
            break;
        case 'c':
            show_sorted_sf_array(sf_array, MAXSEAT);
            break;
        case 'd':
            if ((vacant_seats = compute_empty_seat(sf_array, MAXSEAT)) > 0)
            {
                show_empty_seat(sf_array, MAXSEAT);
                fprintf(stdout, "请问你要选择哪一个空座位(输入f退出)：");
                seat_number = get_seat_number(stdin) - 1;
                if (seat_number >= 0 && seat_number < MAXSEAT)
                {
                    set_seat_inf(sf_array+seat_number, MAXSEAT);
                }
                else
                    break;
            }
            fprintf(stdout, "更新后的座位表:\n");
            show_seat(sf_array, MAXSEAT);
            break;
        case 'e':
            if (compute_empty_seat(sf_array, MAXSEAT) < MAXSEAT)
            {
                fprintf(stdout, "请问你想取消哪个座位(输入f退出)：");
                seat_number = get_seat_number(stdin) - 1;
                if (seat_number >= 0 && seat_number < MAXSEAT)
                {
                    delete_seat_inf(sf_array, seat_number);
                }
                else
                    break;
            }
            fprintf(stdout, "更新后的座位表:\n");
            show_seat(sf_array, MAXSEAT);
            break;

        default:
            break;
        }
        show_options();
        fprintf(stdout, "请输入选项：");
    }

    return 0;
}

void show_seat(struct seat_inf * sf_array, int seat_number)
{
    int index;

    for (index = 0; index < seat_number; index++)
    {
        fprintf(
            stdout, "(%.d) is_book : %.2d %s %s\n", 
            sf_array[index].seat_number,
            sf_array[index].is_book,
            sf_array[index].last_name,
            sf_array[index].first_name
        );
    }
}
void delete_seat_inf(struct seat_inf * sf_array, int seat_number)
{
    sf_array[seat_number].is_book = false;
    strcpy(sf_array[seat_number].first_name, "");
    strcpy(sf_array[seat_number].last_name, "");
}
int get_seat_number(FILE * fp)
{
    int temp;

    if (fscanf(fp, "%d", &temp) != 1)
    {
        while (getc(fp) != '\n')
        {
            ;
        }
        return -1;
    }
    while (getc(fp) != '\n')
    {
        ;
    }
    
    return temp;
}
void set_seat_inf(struct seat_inf * sf, int seats)
{
    fprintf(stdout, "请输入名：");
    my_gets(sf->last_name, MAXCHARS, stdin);
    fprintf(stdout, "请输入姓：");
    my_gets(sf->first_name, MAXCHARS, stdin);
    sf->is_book = true;
}
int compute_empty_seat(struct seat_inf * sf_array, int seats)
{
    int empty_seats = 0;

    for(int i = 0; i < MAXSEAT; i++)
    {
        if (!sf_array[i].is_book)
        {
            empty_seats++;
        }
    }

    return empty_seats;
}
void show_empty_seat(struct seat_inf * sf_array, int seats)
{
    for (int index = 0; index < MAXSEAT; index++)
    {
        if (!sf_array[index].is_book)
            fprintf(stdout, "%.2d 号座位是空的\n", sf_array[index].seat_number);
    }
}
void show_sorted_sf_array(struct seat_inf * sf_array, int seats)
{
    int index;
    struct seat_inf * temp_sf_array = (struct seat_inf *) malloc(seats * sizeof(struct seat_inf));

    for (index = 0; index < seats; index++)
    {
        temp_sf_array[index] = sf_array[index];
    }
    qsort(temp_sf_array, seats, seat_inf_size, compar);
    for (index = 0; index < seats; index++)
    {
        fprintf(
            stdout, "(%.2d) is_book:%.2d %s %s\n", 
            temp_sf_array[index].seat_number, 
            temp_sf_array[index].is_book, 
            temp_sf_array[index].last_name, 
            temp_sf_array[index].first_name
            );
    }
    free(temp_sf_array);
}
int compar(const void * p1, const void * p2)
{
    struct seat_inf * pt1 = (struct seat_inf *) p1;
    struct seat_inf * pt2 = (struct seat_inf *) p2;

    if (strcmp(pt1->last_name, pt2->last_name) > 0)
    {
        return 1;
    }
    else if (strcmp(pt1->last_name, pt2->last_name) == 0)
    {
        return 0;
    }
    else if (strcmp(pt1->last_name, pt2->last_name) < 0)
    {
        return -1;
    }
}
void show_options(void)
{
    fprintf(stdout, "To choose a function, enter its letter label:\n");
    fprintf(stdout, "a) Show number of empty seats\n");
    fprintf(stdout, "b) Show list of empty seats\n");
    fprintf(stdout, "c) Show alphabetical list of seats\n");
    fprintf(stdout, "d) Assign a customer to a seat assignmen\n");
    fprintf(stdout, "e) Delete a seat assignment\n");
    fprintf(stdout, "f) Quit\n");
}
char get_options(FILE * fp)
{
    char ch;
    fscanf(fp, "%c", &ch);
    while (getc(fp) != '\n')
    {
        ;
    }

    return ch;
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