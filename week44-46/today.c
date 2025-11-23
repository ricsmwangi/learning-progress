//was bored and wanted to practice file handling 
// so this is it 
//its on a friday, last day of october
// Meru , 
// 2025


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // time, sleep, usleep

void slow_print(const char *text, int speed) 
{   
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);      // print one character
        fflush(stdout);        // force it to appear immediately
        usleep(speed);         // wait a bit before next char
    }
}
 //removed all the printfs to use slow_print 

// i like attack on titan so
void  library()
{
    slow_print("As ~Commander Erwin~ said\nAS WE RIDE TO CERTAIN DEATH...\n", 80000);
    slow_print("WE TRUST OUR SUCCESSORS TO DO THE SAME FOR US !!\n", 90000);
    slow_print("BECAUSE..!!!! MY SOLDIERS do not BUCKLE or YIELD when faced with cruelty of this world\n", 100000);
    slow_print("MY SOLDIERS PUSH FORWARD!!!!!", 120000);
    slow_print("MY SOLDIERS!!!!!SCREAM!!!!OUT!!\n", 140000);
    slow_print("MY!!SOLDIERS!!!!!RAAAGEEEEEE!!!!!!!!!!!!!!!\n", 160000);
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    int age;
    char location[256]; //in the next code give your char's value of zere:
    char travel[256];
    char name[256]; 
    char line[256];
    FILE *fp;
    clear_screen();

    printf("Username?: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);
    while(getchar() != '\n');//cleans leftover for new line...for fgets to work
                             //this clears buffer input 

    fp = fopen("Travellist.txt", "a+");
    if (fp == NULL)
    {
        printf("The file does not exist!\n");
        return 1;
    }

    if (age >= 20)
    {
        slow_print("Hello there agemate!\n", 100000);
        clear_screen();//don't forget
        library();
        fprintf(fp, "Name:%s\nAge:%d\n", name, age);
        fprintf(fp, "-----------------------------------\n");
    }    

    else 
    {
        slow_print("So where are you from?:(like which part of kenya): ", 100000);
        fgets(location, sizeof(location), stdin);
        slow_print("And which part of the world would you like to travel? ", 100000);
        fgets(travel, sizeof(travel), stdin);
        fprintf(fp, "----Travel list!---\nName:%s\nAge:%d\nLocation:%s\nTravel:%s\n", name, age, location, travel);
        fprintf(fp, "Keep working for IT\n");
        fprintf(fp, "-------------------------------------\n");
    }

    fclose(fp);//make sure to close a file after it done ots job


    fp = fopen("Travellist.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file for reading!\n");
        return 1;
    }

    slow_print("\nContent of the file\n", 100000);
    slow_print("-------------------------\n\n", 100000);


    while(fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);//close it again 

    slow_print("System clear in 5...4.....3......2..........1..........clear now!", 100000);
    clear_screen();
    slow_print("For the dream we began… for the comrades we lost… for humanity’s freedom…\n", 200000);
    


    return 0;
}   

 
