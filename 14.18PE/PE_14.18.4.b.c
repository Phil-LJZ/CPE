#include <stdio.h>
#include <windows.h>
#include <ctype.h>

struct name {
    char first_name[10];
    char middle_name[10];
    char last_name[10];
};

struct insinf {
    int ssn; // 社会保险号
    struct name yourname;
};

void output_struct_array(struct insinf insinf_array, int size);

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码

    struct insinf insinf_array[5] = {
        {
            384095720,
            {
                .first_name = "Smith",
                .middle_name = "Alexander",
                .last_name = "James"
            }
        },
        {
            583957397,
            {
                .first_name = "Johnson",
                .middle_name = "Rose",
                .last_name = "Emily"
            }
        },
        {
            395720675,
            {
                "Johnson",
                "Rose",
                "Emily"
            }
        },
        {
            482318691,
            {
                "Taylor",
                "Grace",
                "Charlotte"
            }
        },
        {
            136456716,
            {
                "Wilson",
                "Thomas",
                "Benjamin"
            }
        }
    };
    
    for (int i = 0; i < 5; i++)
        output_struct_array(*(insinf_array+i), 5);

    return 0;
}
void output_struct_array(struct insinf insinf_array, int size)
{
    fprintf(
        stdout, "%s, %s %c. -- %d\n", 
        insinf_array.yourname.first_name,
        insinf_array.yourname.last_name,
        toupper(*(insinf_array.yourname.middle_name))
    );
}