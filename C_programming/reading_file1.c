#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("//run//media//shinigami//Vault//mwangi.txt", "r");
    char buffer[255];
    printf("%s", buffer);


    fclose(fp);

    return 0;
}
