#include<stdio.h>
int main()
{
    FILE*fp;
    fp = fopen("data.txt", "r");
    if(fp != NULL){
        printf("File does  exist!!\n");
    }else {
        printf("The file does not exist!\n");
        
    }
    
    return 0;
}
