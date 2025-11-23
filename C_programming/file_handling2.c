#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("//run//media//shinigami//Vault//mwangi.txt", "w");
    fprintf(fp, "so am learning file handling and its\nkinda complicating but I'll practice and get it\n");

    fclose(fp);
    return 0; 
}
