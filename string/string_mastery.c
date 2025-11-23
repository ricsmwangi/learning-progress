/*
 * STRING MASTERY COURSE - Complete Guide
 * After completing this, you'll be ready for embedded systems
 * Topics: Advanced string functions, parsing, validation, pointers
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ============================================================
// SECTION 1: STRING FUNCTIONS - strcpy, strcat, strncpy
// ============================================================

void lesson_1_string_copy()
{
    printf("\n=== LESSON 1: String Copy Functions ===\n");
    
    // strcpy - DANGEROUS! Can cause buffer overflow
    char src[50] = "Hello World";
    char dest[50];
    strcpy(dest, src);
    printf("strcpy: '%s' -> '%s'\n", src, dest);
    
    // strncpy - SAFE! Limits copy length
    char dest2[10];
    strncpy(dest2, src, 9);  // Leave room for null terminator
    dest2[9] = '\0';  // Always null-terminate with strncpy
    printf("strncpy (safe): '%s'\n", dest2);
}

// ============================================================
// SECTION 2: STRING CONCATENATION - strcat, strncat
// ============================================================

void lesson_2_string_concat()
{
    printf("\n=== LESSON 2: String Concatenation ===\n");
    
    char str1[50] = "Hello";
    char str2[50] = " World";
    
    // strcat - concatenates str2 to str1
    strcat(str1, str2);
    printf("strcat result: '%s'\n", str1);
    
    // strncat - safe version (limit characters)
    char str3[50] = "Good";
    char str4[50] = "Morning";
    strncat(str3, str4, 3);  // Only add 3 characters: "Mor"
    printf("strncat (3 chars): '%s'\n", str3);
}

// ============================================================
// SECTION 3: STRING SEARCHING - strchr, strstr
// ============================================================

void lesson_3_string_search()
{
    printf("\n=== LESSON 3: String Searching ===\n");
    
    char str[50] = "Programming is fun";
    
    // strchr - find first occurrence of a character
    char *pos = strchr(str, 'o');
    if (pos != NULL)
        printf("Found 'o' at position: %ld\n", pos - str);
    
    // strstr - find substring
    char *substring = strstr(str, "ming");
    if (substring != NULL)
        printf("Found 'ming' in: '%s'\n", substring);
    
    // strpbrk - find first occurrence of any character in set
    char *any = strpbrk(str, "aeiou");
    if (any != NULL)
        printf("First vowel found: '%c' at position %ld\n", *any, any - str);
}

// ============================================================
// SECTION 4: STRING TOKENIZATION - strtok
// ============================================================

void lesson_4_tokenization()
{
    printf("\n=== LESSON 4: String Tokenization (strtok) ===\n");
    
    // strtok splits string by delimiters
    char str[100] = "apple,banana,orange,mango";
    char delimiter[] = ",";
    
    printf("Original: %s\n", str);
    printf("Tokens:\n");
    
    // IMPORTANT: strtok modifies the string! Make a copy first
    char str_copy[100];
    strcpy(str_copy, str);
    
    char *token = strtok(str_copy, delimiter);
    int count = 1;
    
    while (token != NULL)
    {
        printf("  Token %d: '%s'\n", count, token);
        token = strtok(NULL, delimiter);  // Continue tokenizing
        count++;
    }
}

// ============================================================
// SECTION 5: STRING COMPARISON - strcmp, strncmp
// ============================================================

void lesson_5_string_compare()
{
    printf("\n=== LESSON 5: String Comparison ===\n");
    
    char str1[50] = "apple";
    char str2[50] = "apple";
    char str3[50] = "apricot";
    
    // strcmp - compare full strings (case-sensitive)
    printf("strcmp('apple', 'apple'): %d (0 = equal)\n", strcmp(str1, str2));
    printf("strcmp('apple', 'apricot'): %d (negative = str1 < str2)\n", strcmp(str1, str3));
    
    // strncmp - compare first n characters
    printf("strncmp('apple', 'apricot', 2): %d\n", strncmp(str1, str3, 2));
}

// ============================================================
// SECTION 6: CHARACTER VALIDATION (ctype.h)
// ============================================================

void lesson_6_char_validation()
{
    printf("\n=== LESSON 6: Character Validation ===\n");
    
    char str[50] = "Hello123";
    
    printf("String: '%s'\n", str);
    printf("Character analysis:\n");
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("  '%c': ", str[i]);
        
        if (isalpha(str[i]))
            printf("Letter");
        else if (isdigit(str[i]))
            printf("Digit");
        else if (isspace(str[i]))
            printf("Space");
        else
            printf("Other");
        
        if (isupper(str[i]))
            printf(" (UPPERCASE)");
        else if (islower(str[i]))
            printf(" (lowercase)");
        
        printf("\n");
    }
}

// ============================================================
// SECTION 7: CASE CONVERSION
// ============================================================

void lesson_7_case_conversion()
{
    printf("\n=== LESSON 7: Case Conversion ===\n");
    
    char str[50] = "Hello World";
    printf("Original: '%s'\n", str);
    
    // Convert to uppercase
    printf("UPPERCASE: ");
    for (int i = 0; str[i] != '\0'; i++)
        printf("%c", toupper(str[i]));
    printf("\n");
    
    // Convert to lowercase
    printf("lowercase: ");
    for (int i = 0; str[i] != '\0'; i++)
        printf("%c", tolower(str[i]));
    printf("\n");
}

// ============================================================
// SECTION 8: STRING LENGTH & MEMORY
// ============================================================

void lesson_8_string_length()
{
    printf("\n=== LESSON 8: String Length ===\n");
    
    char str[100] = "Programming";
    
    // strlen returns length WITHOUT null terminator  
    printf("String: '%s'\n", str);
    printf("Length (strlen): %zu\n", strlen(str));
    printf("Buffer size: %zu\n", sizeof(str));
    printf("Memory used: %zu bytes (length + 1 for null terminator)\n", strlen(str) + 1);
}

// ============================================================
// SECTION 9: PRACTICAL - Password Validator
// ============================================================

int is_strong_password(char *password)
{
    /*
     * Strong password rules:
     * - At least 8 characters
     * - Contains uppercase letter
     * - Contains lowercase letter
     * - Contains digit
     */
    
    if (strlen(password) < 8)
        return 0;
    
    int has_upper = 0, has_lower = 0, has_digit = 0;
    
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
    }
    
    return has_upper && has_lower && has_digit;
}

void lesson_9_password_validator()
{
    printf("\n=== LESSON 9: Practical - Password Validator ===\n");
    
    char passwords[][50] = {
        "weak",
        "Weak123",
        "Strong@123"
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (is_strong_password(passwords[i]))
            printf("'%s': STRONG ✓\n", passwords[i]);
        else
            printf("'%s': WEAK ✗\n", passwords[i]);
    }
}

// ============================================================
// SECTION 10: STRING POINTERS & ARRAYS
// ============================================================

void lesson_10_string_pointers()
{
    printf("\n=== LESSON 10: String Pointers ===\n");
    
    char str[50] = "Pointers";
    char *ptr = str;  // Pointer to string
    
    printf("String: '%s'\n", str);
    printf("Pointer: %p\n", (void *)ptr);
    printf("First char via pointer: '%c'\n", *ptr);
    
    // Traverse string using pointer
    printf("Characters via pointer: ");
    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
}

// ============================================================
// SECTION 11: 2D ARRAYS OF STRINGS
// ============================================================

void lesson_11_string_arrays()
{
    printf("\n=== LESSON 11: Arrays of Strings ===\n");
    
    // 2D array of strings
    char fruits[3][20] = {
        "apple",
        "banana",
        "orange"
    };
    
    printf("Fruits list:\n");
    for (int i = 0; i < 3; i++)
        printf("  %d: %s (length: %zu)\n", i + 1, fruits[i], strlen(fruits[i]));
}

// ============================================================
// SECTION 12: CHALLENGE - String Reverse
// ============================================================

void string_reverse(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        // Swap characters
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void lesson_12_string_reverse()
{
    printf("\n=== LESSON 12: Challenge - String Reverse ===\n");
    
    char str[50] = "Programming";
    printf("Original: '%s'\n", str);
    
    string_reverse(str);
    printf("Reversed: '%s'\n", str);
}

// ============================================================
// SECTION 13: CHALLENGE - Remove Duplicates
// ============================================================

void remove_duplicates(char *str)
{
    int len = strlen(str);
    int j = 0;
    
    for (int i = 0; i < len; i++)
    {
        int is_duplicate = 0;
        
        // Check if current character exists in earlier positions
        for (int k = 0; k < j; k++)
        {
            if (str[i] == str[k])
            {
                is_duplicate = 1;
                break;
            }
        }
        
        if (!is_duplicate)
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void lesson_13_remove_duplicates()
{
    printf("\n=== LESSON 13: Challenge - Remove Duplicates ===\n");
    
    char str[50] = "mississippi";
    printf("Original: '%s'\n", str);
    
    remove_duplicates(str);
    printf("Without duplicates: '%s'\n", str);
}

// ============================================================
// SECTION 14: CHALLENGE - String to Integer
// ============================================================

int string_to_int(char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    
    // Handle negative sign
    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    
    // Convert string to integer
    for (; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
        }
        else
        {
            return -1;  // Invalid character
        }
    }
    
    return result * sign;
}

void lesson_14_string_to_int()
{
    printf("\n=== LESSON 14: Challenge - String to Integer ===\n");
    
    char str1[20] = "12345";
    char str2[20] = "-789";
    char str3[20] = "invalid";
    
    printf("'%s' -> %d\n", str1, string_to_int(str1));
    printf("'%s' -> %d\n", str2, string_to_int(str2));
    printf("'%s' -> %d\n", str3, string_to_int(str3));
}

// ============================================================
// MAIN MENU
// ============================================================

int main()
{
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║           C STRING MASTERY COURSE - COMPLETE              ║\n");
    printf("║     Master all string concepts before embedded systems     ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    // Run all lessons
    lesson_1_string_copy();
    lesson_2_string_concat();
    lesson_3_string_search();
    lesson_4_tokenization();
    lesson_5_string_compare();
    lesson_6_char_validation();
    lesson_7_case_conversion();
    lesson_8_string_length();
    lesson_9_password_validator();
    lesson_10_string_pointers();
    lesson_11_string_arrays();
    lesson_12_string_reverse();
    lesson_13_remove_duplicates();
    lesson_14_string_to_int();
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║          🎉 STRING MASTERY COMPLETE! 🎉                   ║\n");
    printf("║                                                            ║\n");
    printf("║  Next Steps: Move to EMBEDDED SYSTEMS PROGRAMMING         ║\n");
    printf("║             Topics to cover:                              ║\n");
    printf("║  • Registers & Memory Addresses                           ║\n");
    printf("║  • GPIO & Hardware Interfaces                             ║\n");
    printf("║  • Bitwise Operations                                     ║\n");
    printf("║  • Interrupts & Timers                                    ║\n");
    printf("║  • Serial Communication (UART)                            ║\n");
    printf("║  • PWM & ADC                                              ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    return 0;
}
