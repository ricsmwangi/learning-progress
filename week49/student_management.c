#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 64

// Data structure
typedef struct {
    int id;
    char name[MAX_NAME];
    float gpa;
    char grade;
} Student;

// Container for dynamic array
typedef struct {
    Student *data;
    int count;
    int capacity;
} StudentList;

// ============================================================================
// CORE FUNCTIONS
// ============================================================================

// Initialize a StudentList
StudentList *student_list_create(int initial_capacity) {
    if (initial_capacity <= 0) initial_capacity = 10;
    
    StudentList *list = malloc(sizeof(StudentList));
    if (!list) {
        perror("malloc StudentList");
        return NULL;
    }
    
    list->data = malloc(initial_capacity * sizeof(Student));
    if (!list->data) {
        perror("malloc Student array");
        free(list);
        return NULL;
    }
    
    list->count = 0;
    list->capacity = initial_capacity;
    return list;
}

// Free all memory
void student_list_destroy(StudentList *list) {
    if (!list) return;
    free(list->data);
    free(list);
}

// Add a student, growing array if needed
int student_list_add(StudentList *list, Student s) {
    if (!list) return 0;
    
    if (list->count >= list->capacity) {
        // Double capacity
        int new_capacity = list->capacity * 2;
        Student *tmp = realloc(list->data, new_capacity * sizeof(Student));
        if (!tmp) {
            perror("realloc Student array");
            return 0;
        }
        list->data = tmp;
        list->capacity = new_capacity;
        printf("[Grew capacity to %d]\n", new_capacity);
    }
    
    list->data[list->count++] = s;
    return 1;
}

// Print all students
void student_list_print(StudentList *list) {
    if (!list || list->count == 0) {
        printf("No students.\n");
        return;
    }
    
    printf("\n%-5s %-20s %-8s %-8s\n", "ID", "Name", "GPA", "Grade");
    printf("============================================\n");
    
    for (int i = 0; i < list->count; i++) {
        Student *s = &list->data[i];
        printf("%-5d %-20s %-8.2f %c\n", s->id, s->name, s->gpa, s->grade);
    }
    printf("\n");
}

// Calculate grade from GPA
char gpa_to_grade(float gpa) {
    if (gpa >= 3.7) return 'A';
    if (gpa >= 3.3) return 'A';
    if (gpa >= 3.0) return 'B';
    if (gpa >= 2.5) return 'C';
    if (gpa >= 2.0) return 'D';
    return 'F';
}

// Search by name
int student_list_find_by_name(StudentList *list, const char *name, Student *out) {
    if (!list) return 0;
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->data[i].name, name) == 0) {
            if (out) *out = list->data[i];
            return 1;
        }
    }
    return 0;
}

// Sort by GPA (bubble sort for simplicity)
void student_list_sort_by_gpa(StudentList *list) {
    if (!list || list->count < 2) return;
    
    for (int i = 0; i < list->count - 1; i++) {
        for (int j = 0; j < list->count - i - 1; j++) {
            if (list->data[j].gpa < list->data[j + 1].gpa) {
                Student tmp = list->data[j];
                list->data[j] = list->data[j + 1];
                list->data[j + 1] = tmp;
            }
        }
    }
}

// Get average GPA
float student_list_avg_gpa(StudentList *list) {
    if (!list || list->count == 0) return 0.0;
    
    float sum = 0.0;
    for (int i = 0; i < list->count; i++) {
        sum += list->data[i].gpa;
    }
    return sum / list->count;
}

// ============================================================================
// INTERACTIVE MENU
// ============================================================================

void print_menu(void) {
    printf("\n=== Student Management System ===\n");
    printf("1. Add student\n");
    printf("2. List all students\n");
    printf("3. Search by name\n");
    printf("4. Sort by GPA (highest first)\n");
    printf("5. Show average GPA\n");
    printf("0. Exit\n");
    printf("Select: ");
}

void add_student_interactive(StudentList *list) {
    Student s = {0};
    
    printf("ID: ");
    if (scanf("%d", &s.id) != 1) { while (getchar() != '\n'); return; }
    while (getchar() != '\n');
    
    printf("Name: ");
    if (!fgets(s.name, sizeof(s.name), stdin)) return;
    s.name[strcspn(s.name, "\n")] = 0;
    
    printf("GPA: ");
    if (scanf("%f", &s.gpa) != 1) { while (getchar() != '\n'); return; }
    while (getchar() != '\n');
    
    s.grade = gpa_to_grade(s.gpa);
    
    if (student_list_add(list, s)) {
        printf("✓ Student added.\n");
    } else {
        printf("✗ Failed to add student.\n");
    }
}

void search_interactive(StudentList *list) {
    char name[MAX_NAME];
    printf("Search name: ");
    if (!fgets(name, sizeof(name), stdin)) return;
    name[strcspn(name, "\n")] = 0;
    
    Student result;
    if (student_list_find_by_name(list, name, &result)) {
        printf("\nFound: [%d] %s, GPA: %.2f, Grade: %c\n",
               result.id, result.name, result.gpa, result.grade);
    } else {
        printf("Not found.\n");
    }
}

// ============================================================================
// MAIN
// ============================================================================

int main(void) {
    StudentList *list = student_list_create(10);
    if (!list) return 1;
    
    printf("Welcome to Student Management System\n");
    printf("Capacity: %d students\n\n", list->capacity);
    
    int choice;
    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        
        switch (choice) {
        case 1:
            add_student_interactive(list);
            break;
        case 2:
            student_list_print(list);
            break;
        case 3:
            search_interactive(list);
            break;
        case 4:
            student_list_sort_by_gpa(list);
            printf("✓ Sorted by GPA (highest first).\n");
            student_list_print(list);
            break;
        case 5:
            printf("Average GPA: %.2f\n", student_list_avg_gpa(list));
            break;
        case 0:
            printf("Goodbye!\n");
            student_list_destroy(list);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
