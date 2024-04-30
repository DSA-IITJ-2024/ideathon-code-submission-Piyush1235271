// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <malloc.h>
// #include <string.h>


// struct book{
//     char name[30];
//     char author[30];
//     int id;
//     struct book *next;
// };

// struct student{
//     char name[30];
//     char email[20];
//     char book[20];
//     char a[30];
//     int id;
//     struct student *next;
// };

// struct book *start_lib=NULL;
// struct student *start=NULL;
// struct book *initialize_lib(struct book *);
// struct student *book_issue(struct student *);
// struct student *book_return(struct student *);
// struct book *diplay_lib(struct book *);
// struct book *delete_book(int);
// struct book *add_book(char [],char [],int);
// void display(struct student *);
// void greetings();
// void main_menu();

// int main(){
//     start_lib=initialize_lib(start_lib);
//     greetings();
//     main_menu();
//     return 0;
// }

// void greetings(){
//     printf("\n\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *     ----------------------------     *\n");
//     printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
//     printf("\t\t\t     *     ----------------------------     *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\n\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *       ------------------------       *\n");
//     printf("\t\t\t     *           STUDENT LIBRARY            *\n");
//     printf("\t\t\t     *       ------------------------       *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *       jodhpur,iit_jodhpur,India      *\n");
//     printf("\t\t\t     *     Email: studentlib@gmail.com      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\n\n\t\t\t             Press any key to continue: ");
//     getch();
// }

// void main_menu(){
//     int choice;
//     do{
//         printf("\n\n");
//         printf("\n\t\t\t*************************************************\n");
//         printf("\n\t\t\t\t      MAIN MENU: ");
//         printf("\n\t\t\t\t     1.ISSUE OF BOOKS ");
//         printf("\n\t\t\t\t     2.RETURN OF BOOKS ");
//         printf("\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ");
//         printf("\n\t\t\t\t     4.EXIT\n ");
//         printf("\n\t\t\t*************************************************\n");
//         printf("\n\t\t\t\t      Enter your choice: ");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:{
//                 start=book_issue(start);
//                 break;
//             }
//             case 2:{
//                 start=book_return(start);
//                 break;
//             }
//             case 3:{
//                 display(start);
//                 break;
//             }
//             case 4:{
//                 exit(1);
//             }
//             default:{
//                 printf("\n\t\t\t\t      ...Invalid Option!...\n");
//                 printf("\n\t\t\t\t      Press any key to try again: ");
//                 getch();
//             }
//         }
//     }while(choice!=4);
// }

// struct book *initialize_lib(struct book *start){
//     struct book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5;

//     new_book1=(struct book *)malloc(sizeof(struct book));
//     new_book1->next=NULL;
//     start_lib=new_book1;
//     strcpy(new_book1->name,"The Kite Runner");
//     strcpy(new_book1->author,"Khaled Hosseini");
//     new_book1->id=101;
//     ptr=new_book1;

//     new_book2=(struct book*)malloc(sizeof(struct book));
//     new_book2->next=NULL;
//     strcpy(new_book2->name,"To Kill A Mockingbird");
//     strcpy(new_book2->author,"Harper Lee");
//     new_book2->id=102;
//     ptr->next=new_book2;
//     ptr=new_book2;

//     new_book3=(struct book*)malloc(sizeof(struct book));
//     new_book3->next=NULL;
//     strcpy(new_book3->name,"The Alchemist");
//     strcpy(new_book3->author,"Paulo Coelho");
//     new_book3->id=103;
//     ptr->next=new_book3;
//     ptr=new_book3;

//     new_book4=(struct book*)malloc(sizeof(struct book));
//     new_book4->next=NULL;
//     strcpy(new_book4->name,"Pride And Prejudice");
//     strcpy(new_book4->author,"Jane Austen");
//     new_book4->id=104;
//     ptr->next=new_book4;
//     ptr=new_book4;

//     new_book5=(struct book*)malloc(sizeof(struct book));
//     new_book5->next=NULL;
//     strcpy(new_book5->name,"A Tale Of Two Cities");
//     strcpy(new_book5->author,"Charles Dickens");
//     new_book5->id=105;
//     ptr->next=new_book5;

//     return start_lib;
// }

// struct student *book_issue(struct student *start){
//     struct book *ptr;
//     struct student *ptr2,*new_student;
//     int i=1,id,flag=0;
//     if(start_lib==NULL){
//         printf("\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n");
//     }else{
//         system("cls");
//         ptr=start_lib;
//         printf("\n\t*************** Books Available: ****************\n");
//         while(ptr!=NULL){
//             printf("\n\t_________________________________________________\n");
//             printf("\n\t Book %d",i);
//             printf("\n\t Book Title: %s",ptr->name);
//             printf("\n\t Name of Author: %s",ptr->author);
//             printf("\n\t Book ID: %d",ptr->id);
//             printf("\n\t_________________________________________________\n");
//             ptr=ptr->next;
//             i++;
//         }
//         printf("\n\n\t Enter the Book ID: ");
//         scanf("%d",&id);
//         ptr=start_lib;
//         while(ptr!=NULL){
//             if(ptr->id==id){
//                 flag=1;
//                 break;
//             }
//             ptr=ptr->next;
//         }
//         if(flag==1){
//             ptr=start_lib;
//             while(ptr->id!=id){
//                 ptr=ptr->next;
//             }
//             new_student=(struct student *)malloc(sizeof(struct student));
//             printf("\n\t Enter Student Details:\n ");
//             printf("\n\t Enter your Name: ");
//             scanf("%s",new_student->name);
//             printf("\n\t Enter your Email: ");
//             scanf("%s",new_student->email);
//             strcpy(new_student->book,ptr->name);
//             strcpy(new_student->a,ptr->author);
//             new_student->id=ptr->id;
//             new_student->next=NULL;
//             printf("\n\t Issue of Book ID %d done successfully!\n",new_student->id);
//             printf("\n\n\t*************************************************\n");
//             if(start==NULL){
//                 start=new_student;
//             }else{
//                 ptr2=start;
//                 while(ptr2->next!=NULL){
//                     ptr2=ptr2->next;
//                 }
//                 ptr2->next=new_student;
//             }
//             start_lib=delete_book(new_student->id);
//             printf("\n\n\t Press any key to go to the main menu: ");
//             getch();
//             system("cls");
//         }else{
//             printf("\n\t\t      ...Invalid Option!...\n");
//             printf("\n\t\t      Press any key to try again: ");
//             getch();
//             system("cls");
//         }
//     }
//     return start;
// }

// struct student *book_return(struct student *start){
//     struct student *ptr,*preptr;
//     char bookname[30],authorname[30];
//     int flag=0,id,identity,c=0,d=1;
//     printf("\n\n\t*************** Books Submission: ****************\n");
//     printf("\n\n\t Enter your Book ID: ");
//     scanf("%d",&identity);
//     ptr=start;
//     while(ptr!=NULL){
//         if(ptr->id==identity){
//             flag=1;
//             break;
//         }
//         ptr=ptr->next;
//     }
//     if(flag==1){
//         ptr=start;
//         while(ptr!=NULL){
//             c++;
//             ptr=ptr->next;
//         }
//         ptr=start;
//         while(ptr->id!=identity){
//                 d++;
//             ptr=ptr->next;
//         }
//         ptr=start;
//         if( d==1 ){
//             printf("\n\t_________________________________________________\n");
//             printf("\n\t Student Name: %s",start->name);
//             printf("\n\t Student Email: %s",start->email);
//             printf("\n\t Name of Book Issued: %s",start->book);
//             printf("\n\t_________________________________________________\n");
//             printf("\n\n\t Return of Book ID %d done successfully!\n",identity);
//             printf("\n\n\t*************************************************\n");
//             strcpy(bookname,start->book);
//             strcpy(authorname,start->a);
//             id=start->id;
//             start=start->next;
//             free(ptr);
//             add_book(bookname,authorname,id);
//         }else{
//             ptr=start;
//             while(ptr->id!=identity){
//                 preptr=ptr;
//                 ptr=ptr->next;
//             }
//             printf("\n\t_________________________________________________\n");
//             printf("\n\t Student Name: %s",ptr->name);
//             printf("\n\t Student Email: %s",ptr->email);
//             printf("\n\t Name of Book Issued: %s",ptr->book);
//             printf("\n\t Book ID: %d",ptr->id);
//             printf("\n\t_________________________________________________\n");
//             strcpy(bookname,ptr->book);
//             strcpy(authorname,ptr->a);
//             id=ptr->id;
//             preptr->next=ptr->next;
//             free(ptr);
//             add_book(bookname,authorname,id);
//         }
//         printf("\n\t Thank you! \n\t Do visit again! ");
//         printf("\n\n\t Press any key to go to the main menu: ");
//         getch();
//         system("cls");
//     }else{
//         printf("\n\tSorry the book doesn't exist! Please recheck the entered ID");
//         printf("\n\t\t\t\t      Press any key to try again: ");
//         getch();
//         system("cls");
//     }
//     return start;
// }

// void display(struct student *start){
//     struct student *ptr;
//     ptr=start;
//     while(ptr!=NULL){
//         printf("\n\t************* Details of Students: **************\n");
//         printf("\n\t_________________________________________________\n");
//         printf("\n\t\t Student Name: %s",ptr->name);
//         printf("\n\t\t Student Email: %s",ptr->email);
//         printf("\n\t\t Name of Book Issued: %s",ptr->book);
//         printf("\n\t\t Book ID: %d",ptr->id);
//         printf("\n\t_________________________________________________\n");
//         printf("\n\n\t*************************************************\n");
//         ptr=ptr->next;
//     }
//     printf("\n\n\t Press any key to go to the main menu: ");
//     getch();
//     system("cls");
// }

// struct book *delete_book(int id){
//     struct book *ptr,*preptr;
//     int c=0;
//     ptr=start_lib;
//     while(ptr!=NULL){
//         c++;
//         ptr=ptr->next;
//     }
//     if(c==1){
//         ptr=start_lib;
//         start_lib=NULL;
//         free(ptr);
//     }else if(start_lib->id==id){
//         ptr=start_lib;
//         start_lib=start_lib->next;
//         free(ptr);
//     }else{
//         ptr=start_lib;
//         while(ptr->id!=id){
//             preptr=ptr;
//             ptr=ptr->next;
//         }
//         preptr->next=ptr->next;
//         free(ptr);
//     }
//     return start_lib;
// }

// struct book *add_book(char bookname[30],char authorname[30],int id){
//     struct book *ptr,*new_book;
//     new_book=(struct book *)malloc(sizeof(struct book));
//     strcpy(new_book->name,bookname);
//     strcpy(new_book->author,authorname);
//     new_book->id=id;
//     new_book->next=NULL;
//     if(start_lib==NULL){
//         start_lib=new_book;
//     }else{
//         ptr=start_lib;
//         while(ptr->next!=NULL){
//             ptr=ptr->next;
//         }
//         ptr->next=new_book;
//     }
//     return start_lib;
// }                                          



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_BOOKS 100
// #define MAX_STUDENTS 100

// struct Book {
//     char title[100];
//     char author[100];
//     int id;
// };

// struct Student {
//     char name[100];
//     char email[100];
//     int book_id;
// };

// struct Library {
//     struct Book books[MAX_BOOKS];
//     int num_books;
//     struct Student students[MAX_STUDENTS];
//     int num_students;
// };

// // Function prototypes
// void loadLibrary(struct Library *library, const char *filename);
// void saveLibrary(const struct Library *library, const char *filename);
// void displayMenu();
// void addBook(struct Library *library);
// void issueBook(struct Library *library);
// void returnBook(struct Library *library);
// void displayBooks(const struct Library *library);
// void displayStudents(const struct Library *library);

// int main() {
//     struct Library library;
//     library.num_books = 0;
//     library.num_students = 0;

//     loadLibrary(&library, "library_data.txt");

//     int choice;
//     do {
//         displayMenu();
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         getchar(); // Consume newline character

//         switch(choice) {
//             case 1:
//                 addBook(&library);
//                 break;
//             case 2:
//                 issueBook(&library);
//                 break;
//             case 3:
//                 returnBook(&library);
//                 break;
//             case 4:
//                 displayBooks(&library);
//                 break;
//             case 5:
//                 displayStudents(&library);
//                 break;
//             case 6:
//                 saveLibrary(&library, "library_data.txt");
//                 printf("Library data saved.\n");
//                 break;
//             case 7:
//                 printf("Exiting program.\n");
//                 break;
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     } while(choice != 7);

//     return 0;
// }

// void loadLibrary(struct Library *library, const char *filename) {
//     FILE *file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Could not open file %s for reading.\n", filename);
//         return;
//     }

//     fscanf(file, "%d %d", &library->num_books, &library->num_students);
//     for (int i = 0; i < library->num_books; ++i) {
//         fscanf(file, "%d", &library->books[i].id);
//         fscanf(file, "%s", library->books[i].title);
//         fscanf(file, "%s", library->books[i].author);
//     }

//     for (int i = 0; i < library->num_students; ++i) {
//         fscanf(file, "%s", library->students[i].name);
//         fscanf(file, "%s", library->students[i].email);
//         fscanf(file, "%d", &library->students[i].book_id);
//     }

//     fclose(file);
// }

// void saveLibrary(const struct Library *library, const char *filename) {
//     FILE *file = fopen(filename, "w");
//     if (file == NULL) {
//         printf("Could not open file %s for writing.\n", filename);
//         return;
//     }

//     fprintf(file, "%d %d\n", library->num_books, library->num_students);
//     for (int i = 0; i < library->num_books; ++i) {
//         fprintf(file, "%d\n", library->books[i].id);
//         fprintf(file, "%s\n", library->books[i].title);
//         fprintf(file, "%s\n", library->books[i].author);
//     }

//     for (int i = 0; i < library->num_students; ++i) {
//         fprintf(file, "%s\n", library->students[i].name);
//         fprintf(file, "%s\n", library->students[i].email);
//         fprintf(file, "%d\n", library->students[i].book_id);
//     }

//     fclose(file);
// }

// void displayMenu() {
//     printf("\nLibrary Management System Menu\n");
//     printf("1. Add Book\n");
//     printf("2. Issue Book\n");
//     printf("3. Return Book\n");
//     printf("4. Display Books\n");
//     printf("5. Display Students\n");
//     printf("6. Save Library Data\n");
//     printf("7. Exit\n");
// }

// void addBook(struct Library *library) {
//     if (library->num_books >= MAX_BOOKS) {
//         printf("Library is full. Cannot add more books.\n");
//         return;
//     }

//     struct Book newBook;
//     printf("Enter Book Title: ");
//     fgets(newBook.title, sizeof(newBook.title), stdin);
//     strtok(newBook.title, "\n"); // Remove newline character
//     printf("Enter Author: ");
//     fgets(newBook.author, sizeof(newBook.author), stdin);
//     strtok(newBook.author, "\n"); // Remove newline character
//     printf("Enter Book ID: ");
//     scanf("%d", &newBook.id);
//     getchar(); // Consume newline character

//     library->books[library->num_books++] = newBook;
//     printf("Book added successfully.\n");
// }

// void issueBook(struct Library *library) {
//     if (library->num_students >= MAX_STUDENTS) {
//         printf("Maximum number of students reached. Cannot issue more books.\n");
//         return;
//     }

//     printf("Enter student name: ");
//     fgets(library->students[library->num_students].name, sizeof(library->students[library->num_students].name), stdin);
//     strtok(library->students[library->num_students].name, "\n"); // Remove newline character
//     printf("Enter student email: ");
//     fgets(library->students[library->num_students].email, sizeof(library->students[library->num_students].email), stdin);
//     strtok(library->students[library->num_students].email, "\n"); // Remove newline character

//     displayBooks(library);
//     printf("Enter the ID of the book to issue: ");
//     int bookID;
//     scanf("%d", &bookID);
//     getchar(); // Consume newline character

//     int bookIndex = -1;
//     for (int i = 0; i < library->num_books; ++i) {
//         if (library->books[i].id == bookID) {
//             bookIndex = i;
//             break;
//         }
//     }

//     if (bookIndex == -1) {
//         printf("Book with ID %d not found.\n", bookID);
//         return;
//     }

//     if (library->books[bookIndex].id == -1) {
//         printf("Book with ID %d is already issued.\n", bookID);
//         return;
//     }

//     library->students[library->num_students].book_id = bookID;
//     library->books[bookIndex].id = -1; // Mark book as issued
//     printf("Book '%s' issued successfully to %s.\n", library->books[bookIndex].title, library->students[library->num_students].name);
//     library->num_students++;
// }

// void returnBook(struct Library *library) {
//     printf("Enter student name: ");
//     char studentName[100];
//     fgets(studentName, sizeof(studentName), stdin);
//     strtok(studentName, "\n"); // Remove newline character

//     int studentIndex = -1;
//     for (int i = 0; i < library->num_students; ++i) {
//         if (strcmp(library->students[i].name, studentName) == 0) {
//             studentIndex = i;
//             break;
//         }
//     }

//     if (studentIndex == -1) {
//         printf("Student not found.\n");
//         return;
//     }

//     int bookID = library->students[studentIndex].book_id;
//     int bookIndex = -1;
//     for (int i = 0; i < library->num_books; ++i) {
//         if (library->books[i].id == -1) {
//             bookIndex = i;
//             break;
//         }
//     }

//     if (bookIndex == -1) {
//         printf("No available slots to return the book.\n");
//         return;
//     }

//     library->books[bookIndex].id = bookID; // Mark book as available
//     printf("Book '%s' returned successfully by %s.\n", library->books[bookIndex].title, library->students[studentIndex].name);

//     // Remove the book from student's record
//     for (int i = studentIndex; i < library->num_students - 1; ++i) {
//         library->students[i] = library->students[i + 1];
//     }
//     library->num_students--;
// }

// void displayBooks(const struct Library *library) {
//     printf("\nBooks in Library:\n");
//     for (int i = 0; i < library->num_books; ++i) {
//         printf("ID: %d, Title: %s, Author: %s", library->books[i].id, library->books[i].title, library->books[i].author);
//         if (library->books[i].id == -1) {
//             printf(" (Issued)\n");
//         } else {
//             printf("\n");
//         }
//     }
// }

// void displayStudents(const struct Library *library) {
//     printf("\nStudents in Library:\n");
//     for (int i = 0; i < library->num_students; ++i) {
//         printf("Name: %s, Email: %s, Book ID: %d\n", library->students[i].name, library->students[i].email, library->students[i].book_id);
//     }
// }
// void saveIssuedBooks(const struct Library *library, const char *filename) {
//     FILE *file = fopen(filename, "a"); // Open file in append mode
//     if (file == NULL) {
//         printf("Could not open file %s for writing.\n", filename);
//         return;
//     }

//     for (int i = 0; i < library->num_students; ++i) {
//         fprintf(file, "Issued: Book ID %d, Student Name: %s\n", library->students[i].book_id, library->students[i].name);
//     }

//     fclose(file);
// }

// void saveReturnedBooks(const struct Library *library, const char *filename) {
//     FILE *file = fopen(filename, "a"); // Open file in append mode
//     if (file == NULL) {
//         printf("Could not open file %s for writing.\n", filename);
//         return;
//     }

//     for (int i = 0; i < library->num_students; ++i) {
//         fprintf(file, "Returned: Book ID %d, Student Name: %s\n", library->students[i].book_id, library->students[i].name);
//     }

//     fclose(file);
// }



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
