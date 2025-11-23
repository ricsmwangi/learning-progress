#include<math.h>
#include<stdio.h>

int main()
{
    int number1, number2, number3;
    int result;

    printf("enter number1 to add:");
    scanf("%d", &number1);
    getchar();
    printf("enter number2 to add: ");
    scanf("%d", &number2);
    getchar();
    printf("enter number3 to add: ");
    scanf("%d", &number3);
    getchar();

    result = number1 + number2 + number3;
    printf("the results are:\n%d\n", result);


    return 0;
}