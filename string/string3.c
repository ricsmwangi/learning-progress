//this programs encrypts a string by shifting each character by a fixed number
//challenge 3: simple ceaser cipher
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i;

    printf("Enter a string: ");
    //scanf("%s", str);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] =0;

    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] + 3; //shifts character by 3
    }
    printf("The encrypted string is:\n%s\n", str);

    return 0;
}