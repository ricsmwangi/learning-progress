#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "student.h"


int main()
{ 
    int marks[5]={0};
    char name[256]={0};
    char line[256]={0};
    FILE *fp;
    fp = fopen("Marks.txt", "a+");
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }

    for (int i=0;i<5;i++)
    {
        printf("enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;//okay we use double quotes here i only use one..so had hard //time knowing where the error was
        printf("enter final marks: ");
        scanf("%d", &marks[i]);
        while(getchar() != '\n');

        if (marks[i] <= 39)
        {
            printf("Apply for supplimentary exam %s!!!\n", name);
        }
        else
        {
            printf("%s!!You have qualified to next stage.\n", name);
        }

        fprintf(fp, "Name:%s\nFinal Marks:%d\n", name, marks[i]);
    
    }
    fclose(fp);
    fp = fopen("Marks.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }
    printf("----------------------------------\n");
    printf("contents of the file are here.\n");

  while(fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }
    
 


    fclose(fp);

    return 0;

}