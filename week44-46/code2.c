//program to write 5 names in a file and then read from the file and 
//Display them on a screen

#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char name[100];
    int i;

    

    fp = fopen("test.txt", "a+");
    for(i=0;i<5;i++)

    {
        printf("\nName:-");
        scanf(" %[^\n]", name);
        fprintf(fp, "%s", name);
        fprintf(fp, "\n");
    }

    fclose(fp);
    
    fp = fopen("test.txt", "r");
    printf("\nThe contents of the file are:\n");
    while(fscanf(fp, " %[^\n]", name) != EOF)
    {
        printf("\n%s", name);
    }
    
    fclose(fp);
    
    return 0;
}