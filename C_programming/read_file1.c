#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("//home//shinigami//poem.txt", "r");
    char buffer[255];
    printf("%s", buffer);

    fclose(fp);

    return 0;
}    

