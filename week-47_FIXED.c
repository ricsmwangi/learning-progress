#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/*
 * File I/O and input handling example
 * Demonstrates proper file handling with error checking
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
    name[strcspn(name, "\n")] = 0;
    
    printf("How old are you? ");
    if (fgets(life, sizeof(life), stdin) != NULL) {
        life[strcspn(life, "\n")] = 0;
        if (sscanf(life, "%d", &age) != 1) {
            printf("Couldn't understand that as a number. Setting age to 0.\n");
            age = 0;
        }
    } else {
        age = 0;
    }
    
    printf("Hello, world!\n");
    printf("%s, is back to coding. and he is %d years old.\n", name, age);

    /* Write to file */
    fprintf(fp, "%s - %d years old - Loves coding!\n", name, age);
    fclose(fp);

    assignment();
    return 0;
}
