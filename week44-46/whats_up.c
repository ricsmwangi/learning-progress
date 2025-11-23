#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

//am high af,,,
//in nchiru going to jumuiya.
//every tuesday

void tuesday()
{
    int a;
    int b;
    int tue;
    printf("today is tuesday!\n");
    printf("entre a: ");
    scanf("%d",&a);
    printf("entre b: ");
    scanf("%d", &b);
    while (getchar() != '\n');
    tue = a * b;

    printf("-------------\n");
    printf("the results are here:\n");
    printf("%d\n", tue);
    printf("End of program!\n");
}
void shut_down()
{
#ifdef _WIN32
   system("shutdown");
#else
  system("poweroff");
#endif
}

int main()
{

    tuesday();
    //shut_down();

    return 0;

}