/*am just practicing string searching*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void to_lowercase(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i]= tolower((unsigned char) s[i]);
    }
}

int main()
{
    char str1[50];
    //finding the first occurrence of a character
    char ch;
    printf("Enter a string/statement: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    printf("Enter a character to search: ");
    scanf(" %c", &ch);
    char *pos =strchr(str1, ch);        
    if (pos != NULL)
    {
        printf("found %c at position: %ld\n", ch, pos-str1+1);

    }

    else
    {
        printf("No such character in the statement >>%s\n", str1);
    }
    /*now finding a subdtring is just the same thingg expect that::*/
    getchar();

    char ch2[20];
    printf("Enter a substring to search: ");
    fgets(ch2, sizeof(ch2), stdin);
    ch2[strcspn(ch2, "\n")] = 0;
    char *substring = strstr(str1, ch2);
    if(substring != NULL)
    {
        printf("found substring %s in >>>%s\n", ch2, str1);
    }
    else
    {
        printf("substring %s, not found\n", ch2);
    }

    return 0;
}
