//okay i willl write it here ,,the code before cleaning it was full of missing
//semicolon,,,so work on checking semicolon before moving to the next line:
//am pissed of because that should be the basic of even knowing what c is
//okay just wanted to play my favourite song with the terminal
//so i just play the song in the speaker then tje lyrics display the contents...
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

void clr_screen(void)
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void slowprint(const char *text, int ms)
{
    struct timespec ts = {0, ms * 1000000};
    for(int i = 0; text[i] != '\0'; i++)
    {
        putchar(text[i]);
        fflush(stdout);
        nanosleep(&ts, NULL);
    }
    putchar('\n');
}

int main(void)
{
    char line[200]={0};
    FILE *fp;
    fp =  fopen("juice.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }

    printf("MY FAVOURITE ARTIST IS JUICE WRLD!!\n");
    printf("Hope you enjoy and love this song!\n");
    usleep(5000000);
    clr_screen();

    while(fgets(line, sizeof(line), fp))
    {   //clr_screen();
        slowprint(line, 47);
        usleep(300000);
    }

    fclose(fp);

    return 0;
}
