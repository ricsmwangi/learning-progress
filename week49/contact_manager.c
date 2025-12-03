#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 64
#define MAX_EMAIL 128
#define MAX_PHONE 20
#define MAX_ADDRESS 256

// ============================================================================
// DATA STRUCTURE
// ============================================================================

typedef struct {
    int id;
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
    char address[MAX_ADDRESS];
} Contact;

typedef struct {
    Contact *data;
    int count;
    int capacity;
} ContactList;

// ============================================================================
// CORE FUNCTIONS
// ============================================================================

ContactList *contact_list_create(int initial_capacity) {
    if (initial_capacity <= 0) initial_capacity = 10;
    
    ContactList *list = malloc(sizeof(ContactList));
    if (!list) {
        perror("malloc ContactList");
        return NULL;
    }
    
    list->data = malloc(initial_capacity * sizeof(Contact));
    if (!list->data) {
        perror("malloc Contact array");
        free(list);
        return NULL;
    }
    
    list->count = 0;
    list->capacity = initial_capacity;
    return list;
}

void contact_list_destroy(ContactList *list) {
    if (!list) return;
    free(list->data);
    free(list);
}

int contact_list_add(ContactList *list, Contact c) {
    if (!list) return 0;
    
    if (list->count >= list->capacity) {
        int new_capacity = list->capacity * 2;
        Contact *tmp = realloc(list->data, new_capacity * sizeof(Contact));
        if (!tmp) {
            perror("realloc Contact array");
            return 0;
        }
        list->data = tmp;
        list->capacity = new_capacity;
        printf("[Grew capacity to %d]\n", new_capacity);
    }
    
    list->data[list->count++] = c;
    return 1;
}

void contact_list_print(ContactList *list) {
    if (!list || list->count == 0) {
        printf("No contacts.\n");
        return;
    }
    
    printf("\n%-5s %-20s %-30s %-15s\n", "ID", "Name", "Email", "Phone");
    printf("===================================================================================\n");
    
    for (int i = 0; i < list->count; i++) {
        Contact *c = &list->data[i];
        printf("%-5d %-20s %-30s %-15s\n", c->id, c->name, c->email, c->phone);
    }
    printf("\n");
}

int contact_list_find_by_name(ContactList *list, const char *name, Contact *out) {
    if (!list) return 0;
    
    for (int i = 0; i < list->count; i++) {
        // Case-insensitive search
        if (strstr(list->data[i].name, name)) {
            if (out) *out = list->data[i];
            return 1;
        }
    }
    return 0;
}

int contact_list_find_by_id(ContactList *list, int id, Contact *out) {
    if (!list) return 0;
    
    for (int i = 0; i < list->count; i++) {
        if (list->data[i].id == id) {
            if (out) *out = list->data[i];
            return 1;
        }
    }
    return 0;
}

int contact_list_delete_by_id(ContactList *list, int id) {
    if (!list) return 0;
    
    for (int i = 0; i < list->count; i++) {
        if (list->data[i].id == id) {
            // Shift remaining contacts
            for (int j = i; j < list->count - 1; j++) {
                list->data[j] = list->data[j + 1];
            }
            list->count--;
            return 1;
        }
    }
    return 0;
}

void contact_list_print_detailed(const Contact *c) {
    if (!c) return;
    printf("\n=== Contact Details ===\n");
    printf("ID:      %d\n", c->id);
    printf("Name:    %s\n", c->name);
    printf("Email:   %s\n", c->email);
    printf("Phone:   %s\n", c->phone);
    printf("Address: %s\n", c->address);
}

// ============================================================================
// FILE I/O
// ============================================================================

int contact_list_save(ContactList *list, const char *filename) {
    if (!list || !filename) return 0;
    
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen (write)");
        return 0;
    }
    
    // Write count
    if (fwrite(&list->count, sizeof(int), 1, fp) != 1) {
        perror("fwrite count");
        fclose(fp);
        return 0;
    }
    
    // Write all contacts
    if (fwrite(list->data, sizeof(Contact), list->count, fp) != (size_t)list->count) {
        perror("fwrite contacts");
        fclose(fp);
        return 0;
    }
    
    fclose(fp);
    printf("✓ Saved %d contacts to %s\n", list->count, filename);
    return 1;
}

int contact_list_load(ContactList **list, const char *filename) {
    if (!filename || !list) return 0;
    
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("File not found or cannot be read.\n");
        return 0;
    }
    
    int count;
    if (fread(&count, sizeof(int), 1, fp) != 1) {
        perror("fread count");
        fclose(fp);
        return 0;
    }
    
    ContactList *new_list = contact_list_create(count + 10);
    if (!new_list) {
        fclose(fp);
        return 0;
    }
    
    new_list->data = realloc(new_list->data, count * sizeof(Contact));
    if (!new_list->data) {
        perror("realloc for load");
        free(new_list);
        fclose(fp);
        return 0;
    }
    
    if (fread(new_list->data, sizeof(Contact), count, fp) != (size_t)count) {
        perror("fread contacts");
        contact_list_destroy(new_list);
        fclose(fp);
        return 0;
    }
    
    new_list->count = count;
    fclose(fp);
    
    if (*list) contact_list_destroy(*list);
    *list = new_list;
    printf("✓ Loaded %d contacts from %s\n", count, filename);
    return 1;
}

// ============================================================================
// INTERACTIVE MENU
// ============================================================================

void print_menu(void) {
    printf("\n=== Contact Manager ===\n");
    printf("1. Add contact\n");
    printf("2. List all contacts\n");
    printf("3. Search by name\n");
    printf("4. View contact details\n");
    printf("5. Delete contact\n");
    printf("6. Save contacts\n");
    printf("7. Load contacts\n");
    printf("0. Exit\n");
    printf("Select: ");
}

void add_contact_interactive(ContactList *list) {
    static int next_id = 1;
    Contact c = {0};
    
    c.id = next_id++;
    
    printf("Name: ");
    if (!fgets(c.name, sizeof(c.name), stdin)) return;
    c.name[strcspn(c.name, "\n")] = 0;
    
    printf("Email: ");
    if (!fgets(c.email, sizeof(c.email), stdin)) return;
    c.email[strcspn(c.email, "\n")] = 0;
    
    printf("Phone: ");
    if (!fgets(c.phone, sizeof(c.phone), stdin)) return;
    c.phone[strcspn(c.phone, "\n")] = 0;
    
    printf("Address: ");
    if (!fgets(c.address, sizeof(c.address), stdin)) return;
    c.address[strcspn(c.address, "\n")] = 0;
    
    if (contact_list_add(list, c)) {
        printf("✓ Contact added (ID: %d).\n", c.id);
    } else {
        printf("✗ Failed to add contact.\n");
    }
}

void search_interactive(ContactList *list) {
    char name[MAX_NAME];
    printf("Search name: ");
    if (!fgets(name, sizeof(name), stdin)) return;
    name[strcspn(name, "\n")] = 0;
    
    Contact result;
    if (contact_list_find_by_name(list, name, &result)) {
        contact_list_print_detailed(&result);
    } else {
        printf("Not found.\n");
    }
}

void view_by_id_interactive(ContactList *list) {
    int id;
    printf("Contact ID: ");
    if (scanf("%d", &id) != 1) { while (getchar() != '\n'); return; }
    while (getchar() != '\n');
    
    Contact result;
    if (contact_list_find_by_id(list, id, &result)) {
        contact_list_print_detailed(&result);
    } else {
        printf("Not found.\n");
    }
}

void delete_interactive(ContactList *list) {
    int id;
    printf("Contact ID to delete: ");
    if (scanf("%d", &id) != 1) { while (getchar() != '\n'); return; }
    while (getchar() != '\n');
    
    if (contact_list_delete_by_id(list, id)) {
        printf("✓ Contact deleted.\n");
    } else {
        printf("✗ Not found.\n");
    }
}

// ============================================================================
// MAIN
// ============================================================================

int main(void) {
    ContactList *list = contact_list_create(10);
    if (!list) return 1;
    
    printf("Welcome to Contact Manager\n");
    printf("Type 'contacts.db' to load/save your contacts\n\n");
    
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
            add_contact_interactive(list);
            break;
        case 2:
            contact_list_print(list);
            break;
        case 3:
            search_interactive(list);
            break;
        case 4:
            view_by_id_interactive(list);
            break;
        case 5:
            delete_interactive(list);
            break;
        case 6:
            contact_list_save(list, "contacts.db");
            break;
        case 7:
            contact_list_load(&list, "contacts.db");
            break;
        case 0:
            printf("Goodbye!\n");
            contact_list_destroy(list);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
