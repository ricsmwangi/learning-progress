#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("intro.txt", "w");
    printf("file acces ain't shit\n");

    fclose(fp);

    return 0;
} 