#include<stdio.h>

int main()

{
    int gibb;
FILE *fp;
fp = fopen("reggae.txt", "a+");
fprintf(fp, "nkt man\n", &gibb);

while(fprintf(fp, "%s", gibb) != EOF)
{
    printf("\n%s", gibb);
}
fclose(fp);
    return 0;
}
//am pissed off because i just opened yhis file 
//and there is no single note as to why it has gibb..
//next time not errors,,,,
//for this mistake you are a biginner for the next two weeks
//okay
//	

