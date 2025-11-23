#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void system_clear()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void slow_print(const char *text, long delay_ms)
{
  struct timespec ts;
  ts.tv_sec = delay_ms / 100;
  ts.tv_nsec = (delay_ms%1000)*1000000;


  for(int i = 0; text[i] != '\0'; i++)
  {
    putchar(text[i]);//prints one character
    fflush(stdout);//forces it to appear on display
    nanosleep(&ts, NULL);//time to wait before printing next character
  }
}

int main()
{

int age;
char name[256]={0};
char subject[256]={0};
char msg[256]={0};


printf("\nWhat is your name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")] = 0;
system_clear();

sprintf(msg, "\nHello there! %s.\nHope you are doing fine.\n", name);
slow_print(msg, 50);
printf("\nWhat would you like to learn? ");
fgets(subject, sizeof(subject), stdin);
//subject[strcspn(name, "\n")] = 0; //no ideawhy this line is making my code fail..no idea why it works after commenting on it...nkt C!!

sprintf(msg, "So you like studying %s", subject);
slow_print(msg, 50);

sprintf(msg, "\nHow old are you? ");
slow_print(msg, 50);
scanf("\n%d", &age);
while(getchar() != '\n');


if(age < 18)
{
    sprintf(msg, "\nNot eligible for ID application!\n");
    slow_print(msg, 50);
}
else if(age > 18)
{
    sprintf(msg, "\nProceed with ID application\n");
    slow_print(msg, 50);
}
else{
    sprintf(msg, "\n%d Not a age\n", age);
    slow_print(msg, 50);
}



return 0;
}