#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mind()
{
    printf("We should take care of the brain('hosts the mind').\n");
    printf("That is, the input we accept affects the output.\n");
    printf("\t\t\t~Brain once said~\n");
}

int main()
{
    int age;
    char name[256]={0};//to avoid buffer overflow..just handling better in c
    char anime[256]={0};
    char line[256]={0};
    char data[256]={0};
    FILE *fp;
   

    
    
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;//after using fgets to get user input.this removes the consistent ////extra line

    printf("Age: ");
    scanf("%d", &age);
    while(getchar() != '\n');///also after using the scanf..this removes the consistent extra line 
    

    fp  = fopen("Sunday.txt", "a+");
    if (fp == NULL)
    {
        printf("The file does not exist!\n");
        return 1;//also this is to avoid small small errors...
                 //also its better to write that ine after if statements...for files , pointers..
    }


    if (age >= 17 && age <= 45)
    {
        mind();
        fprintf(fp, "Name:%s\nAge:%d\n", name, age);
        printf("Data copied successfully.\n");
    }
    else if(age >= 0 && age <= 17)
    {
        printf("Explore as much as yo can\nYoung wanderer!!\n");
    }
    else
    {
        printf("Error processing the information provided.\n");
    }

    fclose(fp);


    fp = fopen("/run/media/shinigami/Vault/mwangi.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("---------------------------\n");
    printf("--Contents of the file\n");
    
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }



   
    fclose(fp);

    fp = fopen("Monday.txt", "a+");
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }


    while (1)
    {
        printf(">>>>> ");
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = 0;//master this because you will be using it more

        if(strcmp(data, "quit") == 0)
        {
            break;
        }
        fprintf(fp, "%s", data);
    }
    fclose(fp);


    return 0;
}