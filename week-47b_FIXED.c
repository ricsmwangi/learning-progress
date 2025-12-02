#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void to_lowercase(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower((unsigned char) s[i]);
    }
}

int main()
{
    char string1[100];
    char string2[100];

    printf("Enter first name: ");
    scanf("%99s", string1);
    printf("Enter second name: ");
    scanf("%99s", string2);
    
    to_lowercase(string1);
    to_lowercase(string2);

    printf("%s\n", string1);
    printf("%s\n", string2);

    return 0;
}
