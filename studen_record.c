#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// Structure for student record
typedef struct {
    char name[50];
    int web_design;
    int data_structure;
    int data_science;
    int total;
    float percentage;
} Student;

// Function prototypes
Student* createStudentRecord(char name[], int web, int ds, int dsc);
void displayStudent(void* data);
int compareStudents(void* a, void* b);
void freeStudent(void* data);
void calculateStudentStats(Student* student);
void displayMenu();

// Callback function to display a student record
void displayStudent(void* data) {
    if (data == NULL) return;
    
    Student* student = (Student*)data;
    printf("%-20s %-15d %-15d %-15d %-10d %-10.2f\n", 
           student->name, student->web_design, student->data_structure, 
           student->data_science, student->total, student->percentage);
}

// Callback function to compare two student records by name
int compareStudents(void* a, void* b) {
    if (a == NULL || b == NULL) return -1;
    
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}

// Callback function to free a student record
void freeStudent(void* data) {
    if (data != NULL) {
        free((Student*)data);
    }
}

// Main program
int main() {
    Node* studentList = NULL;
    int choice;
    char name[50];
    int web, ds, dsc;

    printf("Student Record System using Linked List\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter marks for Web Design: ");
                scanf("%d", &web);
                printf("Enter marks for Data Structure: ");
                scanf("%d", &ds);
                printf("Enter marks for Data Science: ");
                scanf("%d", &dsc);

                Student* newStudent = createStudentRecord(name, web, ds, dsc);
                insertNode(&studentList, newStudent);
                printf("Record added successfully!\n");
                break;
            }

            case 2: {
                printf("\nStudent Records:\n");
                printf("-----------------------------------------------------------------\n");
                printf("%-20s %-15s %-15s %-15s %-10s %-10s\n", 
                       "Name", "Web Design", "Data Structure", "Data Science", "Total", "Percentage");
                printf("-----------------------------------------------------------------\n");
                displayList(studentList, displayStudent);
                printf("-----------------------------------------------------------------\n");
                break;
            }

            case 3: {
                printf("Enter student name to search: ");
                scanf("%s", name);
                Student searchKey;
                strcpy(searchKey.name, name);
                
                Node* found = searchNode(studentList, &searchKey, compareStudents);
                if (found != NULL) {
                    printf("\nStudent Details:\n");
                    printf("----------------------------\n");
                    displayStudent(found->data);
                    printf("----------------------------\n");
                } else {
                    printf("Student record not found.\n");
                }
                break;
            }

            case 4: {
                printf("Enter student name to delete: ");
                scanf("%s", name);
                Student deleteKey;
                strcpy(deleteKey.name, name);
                
                deleteNode(&studentList, &deleteKey, compareStudents, freeStudent);
                printf("Record deleted successfully.\n");
                break;
            }

            case 5: {
                freeList(&studentList, freeStudent);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            }

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Create a new student record
Student* createStudentRecord(char name[], int web, int ds, int dsc) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed for new student\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newStudent->name, name);
    newStudent->web_design = web;
    newStudent->data_structure = ds;
    newStudent->data_science = dsc;
    calculateStudentStats(newStudent);

    return newStudent;
}

// Calculate total and percentage for a student
void calculateStudentStats(Student* student) {
    student->total = student->web_design + student->data_structure + student->data_science;
    student->percentage = (float)student->total / 3; // the quickest way to find percentage is to find the average valid for all 
}

// Display menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add new student record\n");
    printf("2. Display all student records\n");
    printf("3. Search for a student record\n");
    printf("4. Delete a student record\n");
    printf("5. Exit\n");
}