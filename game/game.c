// game ight /cards 
//hope it works without more debugging
//so it didn't work fully because i didn't break the loop after correct answer..only that
// then  use fgets to counter error and while getting the number
// then change the number to integer using 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>// for getting the random number 
// you add time to keep the number changing every program runs  


int main()
{
    srand(time(NULL));// this generates a number and sets it as a constant
    const int target = rand() % 27 + 1;// not quite understand it but i will get it//
    int guess;

 
    char name[30]={0};
    char line[256]={0};
    char input[50]={0};
    
    FILE *fp;

    fp = fopen("gamenight.txt", "a+");
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }

    
    printf("Game is you guess a number 1 to 27: \n");


   

    while (1)
    {


        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        printf("Enter number(quit to exit!!): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;


        if (strcmp(input, "quit") == 0)// the quiting prompt
        {
            printf("Quitting game!!\n");
            break;
        }

        if (sscanf(input, "%d", &guess) != 1)// changes the input to a number
        {
            printf("Enter a valid number!!\n");//this counters the error if you didnt type a number
            continue;
        }

        if (guess == target)
        {
            printf("You got it right!You are the king command your servants!!\n");
            printf("%s, haha!!you think yo genius or sum!!\n", name);
            fprintf(fp, "Name:%s\nNumber guess:%d", name, guess);
            printf("Data saved successfully!\n");
            break;
        }
        else
        {
            printf("Chigau!!....Chigau..rudia man!\n");
            printf("yoo!!%s, Si ata utumie sequence any ama odd number !!haha\n", name);
        }

    }



    fp = fopen("gamenight.txt", "r");
    if (fp != NULL)
    {

        printf("---------------------------------\n");
        printf("The contents of game file is:\n");

        while (fgets(line, sizeof(line), fp) != NULL)
        {
            
            printf("%s\n", line);
        }
    }
    
    else
    {
        printf("Error! File Empty!!\n");
    }

    fclose(fp);

    printf("Game ended bullshittly, Thanks Mina for patrticipating!\n");
    printf("Man kibe is so inpatient tukacheze game hope ni yeye atawin!\n");

    return 0;
}    

   