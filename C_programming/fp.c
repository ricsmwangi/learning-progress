#include<stdio.h>
#include<stdlib.h>

int main()
 {
     FILE*fp;
     float total;
     fp = fopen("data.txt", "w+");
     if ( fp == NULL){
         printf("data.txt does not exist, please check!\n");
         exit(1);

     }

     fprintf(fp, 100);
     fscanf("fp", "%f", &total);
     fclose(fp);
     printf("value of the total is "%f\n"", total);

     return 0;
 }
