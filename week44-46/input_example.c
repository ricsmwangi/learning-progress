#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char input[256];  // Buffer for user input
    char line[256];   // Buffer for reading lines

    // Open file for writing (this will create or overwrite the file)
    fp = fopen("user_input.txt", "w+");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    printf("Enter some text (press Enter after each line, type 'quit' to stop):\n");

    // Collect user input and write to file
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline from fgets
        input[strcspn(input, "\n")] = 0;

        // Check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Write the input to file with newline
        fprintf(fp, "%s\n", input);
    }

    fclose(fp);

    // Now read and display the contents
    fp = fopen("user_input.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nContents of the file:\n");
    printf("--------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);  // fgets includes the newline, so no need to add
    }

    fclose(fp);

    return 0;
}