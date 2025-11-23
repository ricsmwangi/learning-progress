//so today i want to advance more on C 
// so i will go the next stage of which i don't know if there are stages
//so this lesson2 involves arrays,.
//this is after the code worked,,,man i always forget the coma/comma/no idea how its spelled
//and am lazy to google or confirm
//okay use a loop tpo keep asking user input then also the loop for constantly
//printing the data collected
//but i still have to knowhow to handle errors
 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

    int mydata[10]={};
    int i=0;

   for(int i=0;i<10;i++)
   {
      printf("enter any number: ");
      scanf("%d", &mydata[i]);

   }
    

    for (int i=0;i<10;i++)
    {
        printf("%d\n", mydata[i]);
    }


    return 0;
}