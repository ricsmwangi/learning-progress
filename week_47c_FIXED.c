#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char food[100];
    char dest1[200];
    char name[] = "Mwangi";
    char best[] = "popcorns";

    printf("Your favourite food: ");
    if (fgets(food, sizeof(food), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }
    food[strcspn(food, "\n")] = 0;

    strncpy(dest1, food, sizeof(dest1) - 1);
    dest1[sizeof(dest1) - 1] = '\0';
    printf("%s, unapenda: %s\n", name, dest1);

    strncat(dest1, " ", sizeof(dest1) - strlen(dest1) - 1);
    strncat(dest1, best, sizeof(dest1) - strlen(dest1) - 1);
    printf("%s, unapenda: %s\n", name, dest1);

    return 0;
}
