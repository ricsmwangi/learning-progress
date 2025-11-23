// no idea what program to write
//anyway at the end there will be some lines

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

void safari()
{
    printf("This is a Safari Appreciation\n");
    printf("Safari is a Cigarrette dold in manny parts of the world\n");
    printf("They contain some Nicotine\n");
    printf("Liked for it gives a headrush\n");
    printf("It's compatible with:");
    printf("1: Alcohol.\n2:Jaba/Muguka.\n3:And also its also independent.\n");
    printf("Safari for life!!\n");
}


int main()
{
    char name[100];
    char input[100];
    char types[20];
    const char *question[]= {"yes", "no"};
    char choice[20];
    int age;
    int t;
    char cig_list[50][256];
    int count = 0;
    char choice2[40];
    

    printf("Let the Program begin!\n");
    printf("Username: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Enter age: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;


    if(sscanf(input, "%d", &age) != 1)
    {
        printf("Enter a valid number!\n");
        return 1; //first time after using this if statement 
        //changes the input collected by the fgets to an integer
    }

    if (age >= 1 && age <= 17)
    {
        printf("Still in school!\n");
        printf("Wrong program!!\n");
        printf("Session terminated!\n");
        return 0;//you can end the program her by adding this line ...
        //safer t do this to completely end the session
    }

    else if (age >= 18 && age <= 45)
    {
        printf("%s, Do you Like Smoking Cigarettes?(yes/no): ", name);
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0;


        if(strcmp(choice, "yes") == 0)
        {
            printf("Wise choice Legend!\n");
            printf("So this program talks more on the drug!\n");
            printf("How many types do you know? ");
            fgets(types, sizeof(types), stdin);
            types[strcspn(types, "\n")] = 0;

            if(sscanf(types, "%d", &t) != 1)
            {
                printf("Enter a valid number\n");
                return 1;//then when using fgets make sure to use fgets the whole program...
            }


            printf("Enter the types you know(type 'quit to stop):\n");
            for(int i = 0; i<t;i++)
            {
                printf("Cigarrete %d: ", i + 1);
                fgets(cig_list[i], sizeof(cig_list[i]), stdin);
                cig_list[i][strcspn(cig_list[i], "\n")] = 0;

                if(strcmp(cig_list[i], "Quit") == 0 || strcmp(cig_list[i], "quit") == 0)
                {
                    printf("Quitting listing!1\n");
                    break;
                }
                count++;
            }

            for(int i = 0; i < count; i++)//for now comparinng after listing
            { 

               if (strcmp(cig_list[i], "Safari") == 0 || strcmp(cig_list[i], "safari") == 0)
                {
                    printf("aah...So %s, you like safari!\n", name);
                    printf("Okay just a message from Safari:\n");
                    safari();
                    printf("\n\nHope the message was helpful:\n");
                    printf("Another thing is that:\nExessive consuption of Tobacco kills\n");

                }

            } 

            printf("Good job for participating!\n");
        }

        else if (strcmp(choice, "no") == 0)
        {
            printf("The End!\n");
        }

    }

    else 
    {
        printf("Having the privilledge to experince more life/life more is no easy thing.\n");
        printf("Hope you have those wise words or sayings!\n");
    }


    return 0;
}////so waht is remaining is finish strings and enter dynamic memory!!