//was here just to practice functions but 
//ended up writing a happy birthday code
//anyway i want to collect the data input 
//then save it in a birthday.txt file
//its quarter past two btw ..
//i like coding at night so much peaceful.
//cool no noise..


#include<stdio.h>
#include<stdlib.h>
void birthday(int age, char name[]) //thats how you create a function
{
    printf("Happy birthday to you!\n");
    printf("Happy birthday to you!\n");
    printf("Happy birthday dear..%s.., happy birthday to you!!!\n", name);
    printf("Happy %dth, birthday\n", age + 1);
}

int main()
{
    int age;
    char name[256];
    char line[256];
    FILE *fp;
    printf("What is your name?: ");
    scanf("%s", name);
    printf("How old are you now!: ");
    scanf("%d", &age);

    if (age <= 18)
    {
        printf("Hello there teenager!\n\n");
    }
    else if (18 <= age <=99)
    {
        printf("So we grab a drink or what!!\n\n");
    }
    else
    {
        printf("Are you a alien!!\n\n");
    }


    birthday(age, name); //that is how you call a function
                          //instead of using so many printfs..this is much simpler

    printf("My gift for you today is a 'Porsche 911'\nHope you love it!\n");



    fp = fopen("birthday.txt", "a+");
    if (fp == NULL)
    {
        printf("error opening the file\n");
        return 1;
    }

    fprintf(fp, "Name:%s\nAge:%d\n", name, age);
    fprintf(fp, "Gift:Porsche 911\n\n");

    fclose(fp);

    //fp = fopen("birthday.txt", "r");
    //if (fp == NULL)
    //{
    //    printf("Error opening file for reading\n");
    //    return 1;
    //}

    //printf("The contents of the file:\n");
    //printf("---------------------------\n\n");

    //while (fgets(line, sizeof(line), fp) != NULL) 
    //{ 

       // printf("%s", line);

    //}

    //fclose(fp);


    return 0;
}