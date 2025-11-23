#include<stdio.h>
#include<stdlib.h>
#include<string.h>/*man how could i forget the header string and am working with strings*/

int main()
{
  char food[100];
  char dest1[200];
  char name[]="Mwangi";


  printf("your favourite food: ");
  fgets(food, sizeof(food), stdin);
  food[strcspn(food,  "\n")] = 0;

  strncpy(dest1, food, 199);
  printf("%s, unapenda >>>.. %s.\n", name, dest1);

  char best[9]="popcorns";/*the code did run once and well now its not running as i want to and there is no error...trying to use gdb and its not even running ..man..guess i should sleep but i dont even feel like //*/
  strncat(dest1, best, 4);
  printf("%s, unapenda >>> %s... na ..\n", name, dest1);

  



  return 0;
}