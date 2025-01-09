static int mode = 0;
static int distance = 0;
static float oil_quantity = 0;

void set_mode(int);
void get_info(void);
void show_info(void);
void get_digit(int *);
void get_float(float *);

void set_mode(int mode1)
{
    extern int mode;
    mode = mode1;
}
void get_info(void)
{
    extern int distance;
    extern float oil_quantity;
    extern int mode;

    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers:");
        get_digit(&distance);
        printf("Enter fuel consumed in liters:");
        get_float(&oil_quantity);
    }
    else if (mode == 1)
    {
        printf("Enter distance traveled in miles:");
        get_digit(&distance);
        printf("Enter fuel consumed in gallons:");
        get_float(&oil_quantity);
    }
    else if (mode > 0)
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        printf("Enter distance traveled in miles: ");
        get_digit(&distance);
        printf("Enter fuel consumed in gallons:");
        get_float(&oil_quantity);
    }
}
void show_info(void)
{
    if (mode == 0)
    {
        printf("Fuel consumption is %f liters per 100 km.\n", oil_quantity / distance * 100);
    }
    else if (mode > 0)
    {
        printf("Fuel consumption is %f miles per gallon.\n", distance / oil_quantity);
    }
}
void get_digit(int * distance)
{
    scanf("%d", distance);
    while (getchar() != '\n')
    {
        continue;
    }
}
void get_float(float * oil_quantity)
{
    scanf("%f", oil_quantity);
    while (getchar() != '\n')
    {
        continue;
    }
}