//the challenge is to check for palindrome  
//ie 
//determine if the same string reads same as forward and backward

#include<stdio.h>
#include<string.h>

int main()
{
    char str[200];
    int i;
    int len;
    int flag = 1;


    printf("enter a string: ");
    scanf("%s", str);


    len = strlen(str);
    for(i = 0; i < len/2; i++);
    {
        if (str[i] != str[len - i -1])
        {
            flag = 0;
    
        }

    }
    
    if (flag)
        printf("It is a palindrome!\n");
    else
        printf("Not a palindrome!\n");

    return 0;
   

}