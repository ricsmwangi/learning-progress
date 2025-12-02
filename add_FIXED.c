#include<stdio.h>

int main()
{
    int number1, number2, number3;
    int sum;

    printf("enter number1 to add: ");
    scanf("%d", &number1);
    printf("enter number2 to add: ");
    scanf("%d", &number2);
    printf("enter number3 to add: ");
    scanf("%d", &number3);

    sum = number1 + number2 + number3;
    printf("The sum is: %d\n", sum);

    return 0;
}
