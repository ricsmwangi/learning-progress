//for practice of strings
//i haven't read the strings documentation atleast not all of it;;
//but i was surfing the web and i found out that 
//copilot is a beter tutor that even chatgpt 
//copilot is alot more better that pt so i want to learn a little strings 
//with copilot before i use more notes
//so this code takes user input and prints the reverse of it

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str[100];
    int i, len;

    printf("Enter a string: ");
    //scanf("%s", str);//this only accepts up to the first whitespace///for full names use fgets
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;//clears the new ;ine created by the fgets

    len = strlen(str);//for geting the length of the string
    printf("The reversed string is:\n");
    //use a for loop
    for (i = len - 1;i >= 0; i--)//reverses the string
    {
        printf("%c", str[i]);
    }
    printf("\n");//tis helps print the output in one line

    return 0;

}