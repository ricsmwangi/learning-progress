/* String searching and manipulation practice */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void to_lowercase(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower((unsigned char) s[i]);
    }
}

int main()
{
    char str1[50];
    char ch;
    
    printf("Enter a string/statement: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("Enter a character to search: ");
    scanf(" %c", &ch);
    
    char *pos = strchr(str1, ch);        
    if (pos != NULL)
    {
        int position = pos - str1;  /* 0-based index */
        printf("Found '%c' at position: %d\n", ch, position);
    }
    else
    {
        printf("No such character in the statement: %s\n", str1);
    }
    
    getchar();

    char substring[20];
    printf("Enter a substring to search: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = 0;
    
    char *found = strstr(str1, substring);
    if(found != NULL)
    {
        printf("Found substring '%s' in '%s'\n", substring, str1);
    }
    else
    {
        printf("Substring '%s' not found\n", substring);
    }

    return 0;
}
