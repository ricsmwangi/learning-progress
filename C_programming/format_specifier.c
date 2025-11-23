#include<stdio.h>
int main()
{
    float item1 = 4.999;
    float item2 = 100.66;
    float item3 = 54;
    char name[] = "Erick";
    
    printf("Here is your item list:%s\n", name);
    printf("Item 1:$%-5.2f\n", item1);
    printf("Item 2:$%-5.2f\n", item2);
    printf("Item 3:$%-5.2f\n", item3);
    return 0;
}
