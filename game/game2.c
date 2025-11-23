// game ight /cards 
//hope it works without more debugging
//

#include<stdio.h>
#include<string.h>


int main()
{
    int a =10;
    int game;

 
    char name[100]={0};
    char line[256]={0};
    
    FILE *fp;

    fp = fopen("gamenight.txt", "a+");
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }

    
    printf("Game is you gues a number 1 to 100: \n");


    while (1)
    {

        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter number: ");
        scanf("%d\n", &game);
        while(getchar() != '\0');


         
        if (game ==  a)
        {
            printf("You got it right!!\n");

        }
          else
        {
            printf("Chigau!!\n haha!!%s", name);
        }

        fprintf(fp, "Name:%s\nNumber Guessed!:%d\n", name, game);

    }

   fclose(fp);

    return 0;
}