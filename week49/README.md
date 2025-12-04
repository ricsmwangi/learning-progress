# Week 49: Structs & Dynamic Memory

## Projects

### Student Management System
A command-line application demonstrating **structs** and **dynamic memory allocation** in C.

**Features:**
- Add, list, and search students by name
- Automatic GPA-to-grade conversion (A–F)
- Sort students by GPA (highest first)
- Calculate class average GPA
- Growable dynamic array (capacity doubles as needed)
- Safe memory allocation with error checking

**What you learn:**
- Struct definition and member access (`.` and `->` operators)
- Dynamic memory: `malloc()`, `realloc()`, `free()`
- Array growth pattern (vector-like container)
- Input validation and user-interactive menus
- String handling with `fgets()` and `strcspn()`

**Build & Run:**
```bash
gcc student_management.c -o student_management
./student_management
```

**Menu:**
```
1. Add student
2. List all students
3. Search by name
4. Sort by GPA (highest first)
5. Show average GPA
0. Exit
```

**Example Session:**
```
ID: 1
Name: Alice
GPA: 3.8
✓ Student added.

ID: 2
Name: Bob
GPA: 3.2
✓ Student added.

[List all students]
ID    Name                 GPA      Grade
============================================
1     Alice                3.80     A
2     Bob                  3.20     B
```

## Key Concepts

### Structs
```c
typedef struct {
    int id;
    char name[64];
    float gpa;
    char grade;
} Student;
```
Groups related data in a single type. Easy to pass around and organize.

### Dynamic Memory
```c
// Allocate
Student *s = malloc(sizeof(Student));
if (!s) { perror("malloc"); return 1; }

// Use
s->id = 1;

// Free
free(s);
```
Allocate only what you need, only when you need it. Always check return values and free when done.

### Growable Array
```c
typedef struct {
    Student *data;
    int count;
    int capacity;
} StudentList;
```
Starts with a fixed capacity; when full, `realloc()` doubles the size. Efficient and flexible.

## Next Steps
- Add file persistence (save/load students to a file)
- Remove students by ID
- Use `qsort()` for faster sorting
- Input validation (GPA must be 0.0–4.0)

## Files
- `student_management.c` — Main program
- `STRUCTS_AND_DYNAMIC_MEMORY.txt` — Concept guide
- `WEEK49_COMPLETE_GUIDE.txt` — Deep reference
- `SMS3413_CAT1_ANSWERS.txt` — Exam answers (unrelated, reference only)

---
**Status:** Ready for systems programming basics.
