#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/*
 * Simple warm-up program printing a few lines.
 * Feel free to expand this with input handling, loops, or file I/O.
 */
void assignment(void) {
    printf("So the thing is I was just chilling then boom\n");
    printf("Chaos after chaos\n");
    printf("But I really love turning chaos into code\n");
}
int main()
{
    char name[100];
    char life[100];
    int sleeping;
    int age;
    FILE *fp;
    fp = fopen("Updatelog.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; /* this removes the new line created by fgets */
    printf("How old are you? ");
    if (fgets(life, sizeof(life), stdin) != NULL) {
        life[strcspn(life, "\n")] = 0; /* trim newline */
        if (sscanf(life, "%d", &age) != 1) {
            printf("Couldn't understand that as a number. Setting age to 0.\n");
            age = 0;
        }
    } else {
        age = 0;
    }
    
    printf("Hello, world!\n");
    printf("%s, is back to coding. and he is %d years old.\n", name, age);


    assignment();
    return 0;
}