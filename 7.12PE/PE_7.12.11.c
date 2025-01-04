#include <stdio.h>

#define artichoke_price 2.05
// 洋蓟单价
#define dessert_menu_price 1.15
// 甜菜单价
#define carrot_price 1.09
// 胡萝卜单价

int main(void){
    int category;
    float input;
    float artichoke_amount;
    float dessert_menu_amount;
    float carrot_amount;
    float total_price;
    float discount;
    float total;
    float packaging_shipping;
    float total_price_of_vegetables;

    printf("请输入类别和磅数：");
    while ((scanf("%d %f", &category, &input)) == 2 && category != 'q')
    {
        switch (category)
        {
        case 1:
            artichoke_amount += input;
            total += input;
            total_price_of_vegetables += input * artichoke_price;
            break;
        case 2:
            dessert_menu_amount += input;
            total += input;
            total_price_of_vegetables += input * dessert_menu_price;
            break;
        case 3:
            carrot_amount += input;
            total += input;
            total_price_of_vegetables += input * carrot_price;
            break;
        
        default:
            printf("输入错误");
            break;
        }
        printf("请输入类别和磅数：");
    }
    
    if (total_price_of_vegetables == 100){
        discount = total_price_of_vegetables * 0.05;
        total_price_of_vegetables *= 0.95;
    }

    if (total <= 5)
    {
        packaging_shipping = 6.5;
    }
    else if (total > 5 && total < 20)
    {
        packaging_shipping = 14;
    }
    else if (total >= 20)
    {
        packaging_shipping = 14 + (total - 20) * 0.5;
    }

    total_price = total_price_of_vegetables + packaging_shipping;
    
    printf("洋蓟总量：%f\n甜菜总量：%f\n胡萝卜总量：%f\n总量：%f\n蔬菜总价：%f\n折扣：%f\n运、包装费：%f\n总价：%f\n", 
            artichoke_amount,
            dessert_menu_amount,
            carrot_amount,
            total,
            total_price_of_vegetables,
            discount,
            packaging_shipping,
            total_price
    );
    
    return 0;
}