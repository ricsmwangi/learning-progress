#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<>

void learn()
{
    printf("Good morning Rics!.\n");
    printf("Hope you had a great night.\n");
    printf("Now its time to continue learning C programming.\n");
    //btw nearly forgot all the commas...nkt how could i be this bullshit 
}

int main()
{
    //today no prompting the user with age shit
    char name[256]={0};///to avoid garbage in the memory...that is the name string is set to zerpo
    char topic[256]={0};//then one thing you already defined the size so no need t repeat the sozeof///just write the value 256, or the vakue youve given the array

    FILE *fp;

    fp = fopen("LN1.txt", "a+");
    if(fp == NULL)
    {
        printf("file does not exist!");//handling file error
        return 1;///also to avoid small bullshit errors
    }

    printf("What is your name?: ");
    fgets(name, 256, stdin);
    name[strcspn(name, "\n")] = 0;///yah nuke that new line like hell!!!
    

    printf("Okay the message is here!\n");
    learn();///also use more and more of functions
    printf("So what are you gonna learn today?:\n");//good observation..keep the question out of the loop 
    while (1)///loop starts
    {
       printf(">>>>>> ");///prompt user
       fgets(topic, 256, stdin);//gets the user input
       topic[strcspn(topic, "\n")] = 0;//must remove the new line created ///MUST FOR QUIT TO WORK
     ///for code logic to work.//
       if (strcmp(topic, "quit") == 0)//quit is set to 0 because means false in c and false means stop..so if you set it to 1 the loop continues;;
       {
           break;///this breaks the loop if user types quit
       }


    }
    



    fprintf(fp, "Name:%s\nTopic:%s\n", name, topic);//saves the user data

    fclose(fp);//must close the file to avoid segmaentation error or buffer overflow


    return 0;
}