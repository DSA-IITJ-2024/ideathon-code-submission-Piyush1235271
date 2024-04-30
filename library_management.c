#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STUDENTS 100

struct Book {
    char title[100];
    char author[100];
    int id;
};

struct Student {
    char name[100];
    char email[100];
    int book_id;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
    struct Student students[MAX_STUDENTS];
    int num_students;
};

// Function prototypes
void loadLibrary(struct Library *library, const char *filename);
void saveLibrary(const struct Library *library, const char *filename);
void displayMenu();
void addBook(struct Library *library);
void issueBook(struct Library *library);
void returnBook(struct Library *library);
void displayBooks(const struct Library *library);
void displayStudents(const struct Library *library);
void saveIssuedBooks(const struct Library *library, const char *filename);
void saveReturnedBooks(const struct Library *library, const char *filename);

int main() {
    struct Library library;
    library.num_books = 0;
    library.num_students = 0;

    loadLibrary(&library, "library_data.txt");

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                issueBook(&library);
                break;
            case 3:
                returnBook(&library);
                break;
            case 4:
                displayBooks(&library);
                break;
            case 5:
                displayStudents(&library);
                break;
            case 6:
                saveLibrary(&library, "library_data.txt");
                printf("Library data saved.\n");
                break;
            case 7:
                saveIssuedBooks(&library, "issued_books.txt");
                saveReturnedBooks(&library, "returned_books.txt");
                printf("Issued and returned books data saved.\n");
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}

void loadLibrary(struct Library *library, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    fscanf(file, "%d %d", &library->num_books, &library->num_students);
    for (int i = 0; i < library->num_books; ++i) {
        fscanf(file, "%d", &library->books[i].id);
        fscanf(file, "%s", library->books[i].title);
        fscanf(file, "%s", library->books[i].author);
    }

    for (int i = 0; i < library->num_students; ++i) {
        fscanf(file, "%s", library->students[i].name);
        fscanf(file, "%s", library->students[i].email);
        fscanf(file, "%d", &library->students[i].book_id);
    }

    fclose(file);
}

void saveLibrary(const struct Library *library, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", library->num_books, library->num_students);
    for (int i = 0; i < library->num_books; ++i) {
        fprintf(file, "%d\n", library->books[i].id);
        fprintf(file, "%s\n", library->books[i].title);
        fprintf(file, "%s\n", library->books[i].author);
    }

    for (int i = 0; i < library->num_students; ++i) {
        fprintf(file, "%s\n", library->students[i].name);
        fprintf(file, "%s\n", library->students[i].email);
        fprintf(file, "%d\n", library->students[i].book_id);
    }

    fclose(file);
}

void displayMenu() {
    printf("\nLibrary Management System Menu\n");
    printf("1. Add Book\n");
    printf("2. Issue Book\n");
    printf("3. Return Book\n");
    printf("4. Display Books\n");
    printf("5. Display Students\n");
    printf("6. Save Library Data\n");
    printf("7. Exit\n");
}

void addBook(struct Library *library) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    strtok(newBook.title, "\n"); // Remove newline character
    printf("Enter Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    strtok(newBook.author, "\n"); // Remove newline character
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar(); // Consume newline character

    library->books[library->num_books++] = newBook;
    printf("Book added successfully.\n");
}

void issueBook(struct Library *library) {
    if (library->num_students >= MAX_STUDENTS) {
        printf("Maximum number of students reached. Cannot issue more books.\n");
        return;
    }

    printf("Enter student name: ");
    fgets(library->students[library->num_students].name, sizeof(library->students[library->num_students].name), stdin);
    strtok(library->students[library->num_students].name, "\n"); // Remove newline character
    printf("Enter student email: ");
    fgets(library->students[library->num_students].email, sizeof(library->students[library->num_students].email), stdin);
    strtok(library->students[library->num_students].email, "\n"); // Remove newline character

    displayBooks(library);
    printf("Enter the ID of the book to issue: ");
    int bookID;
    scanf("%d", &bookID);
    getchar(); // Consume newline character

    int bookIndex = -1;
    for (int i = 0; i < library->num_books; ++i) {
        if (library->books[i].id == bookID) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        printf("Book with ID %d not found.\n", bookID);
        return;
    }

    if (library->books[bookIndex].id == -1) {
        printf("Book with ID %d is already issued.\n", bookID);
        return;
    }

    library->students[library->num_students].book_id = bookID;
    library->books[bookIndex].id = -1; // Mark book as issued
    printf("Book '%s' issued successfully to %s.\n", library->books[bookIndex].title, library->students[library->num_students].name);
    library->num_students++;
}

void returnBook(struct Library *library) {
    printf("Enter student name: ");
    char studentName[100];
    fgets(studentName, sizeof(studentName), stdin);
    strtok(studentName, "\n"); // Remove newline character

    int studentIndex = -1;
    for (int i = 0; i < library->num_students; ++i) {
        if (strcmp(library->students[i].name, studentName) == 0) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    int bookID = library->students[studentIndex].book_id;
    int bookIndex = -1;
    for (int i = 0; i < library->num_books; ++i) {
        if (library->books[i].id == -1) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        printf("No available slots to return the book.\n");
        return;
    }

    library->books[bookIndex].id = bookID; // Mark book as available
    printf("Book '%s' returned successfully by %s.\n", library->books[bookIndex].title, library->students[studentIndex].name);

    // Remove the book from student's record
    for (int i = studentIndex; i < library->num_students - 1; ++i) {
        library->students[i] = library->students[i + 1];
    }
    library->num_students--;
}

void displayBooks(const struct Library *library) {
    printf("\nBooks in Library:\n");
    for (int i = 0; i < library->num_books; ++i) {
        printf("ID: %d, Title: %s, Author: %s", library->books[i].id, library->books[i].title, library->books[i].author);
        if (library->books[i].id == -1) {
            printf(" (Issued)\n");
        } else {
            printf("\n");
        }
    }
}

void displayStudents(const struct Library *library) {
    printf("\nStudents in Library:\n");
    for (int i = 0; i < library->num_students; ++i) {
        printf("Name: %s, Email: %s, Book ID: %d\n", library->students[i].name, library->students[i].email, library->students[i].book_id);
    }
}

void saveIssuedBooks(const struct Library *library, const char *filename) {
    FILE *file = fopen(filename, "w"); // Open file in write mode
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < library->num_students; ++i) {
        fprintf(file, "Issued: Book ID %d, Student Name: %s\n", library->students[i].book_id, library->students[i].name);
    }

    fclose(file);
}


void saveReturnedBooks(const struct Library *library, const char *filename) {
    FILE *file = fopen(filename, "a"); // Open file in append mode
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < library->num_students; ++i) {
        fprintf(file, "Returned: Book ID %d, Student Name: %s\n", library->students[i].book_id, library->students[i].name);
    }

    fclose(file);
}
