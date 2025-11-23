#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*void to_lowercase(char *s) this is the function ...
{
  for (int i =0; s[i]; i++){
    s[i]= tolower((unsigned char) s[i])
  }
}*/


/*so to just call it
to_lowercase(string1);
to_lowercase(string2);*/

int main()
{
  char string1[100];
  char string2[100];

  printf("Enter first name: ");
  scanf("%99s", string1); /*SINCE WE USED THE CHAR AT 100 WE MINUS ONE AD  PASS THAT TO SCANF..*/
  printf("Enter second name: ");
  scanf("%99s", string2); /*then after controlling the buffer in the scanf there is no need for getchar..no new line produced */
  
  for(int i = 1; string1[i]; i++) /*man what a bullshit mistake i just made here,,,putting a semicolon after a for loop...*/
  {
    string1[i]= tolower((unsigned char) string1[i]); 
  }
  for(int i = 1; string2[i]; i++)
  {
    string2[i]= tolower((unsigned char) string2[i]); /*then instead of havein many forr loops you can wrap that i a function and then just    call it*/
  }

  printf("%s\n", string1);
  printf("%s\n", string2);


  return 0;
}

