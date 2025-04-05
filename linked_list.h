#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32  
    #define OS "Windows"  
#elif __linux__  
    #define OS "Linux"  
#elif __APPLE__  
    #define OS "macOS"  
#else  
    #define OS "Unknown"  
#endif  

#ifdef __cplusplus  
extern "C" {  
#endif  




#define LOG(msg) printf("[DEBUG] %s (%s:%d)\n", msg, __FILE__, __LINE__)  

// Structure for a node (generic implementation)
typedef struct Node {
    void* data;         // Generic pointer to hold any data type
    struct Node* next;  // Pointer to next node
} Node;

// Function declarations
Node* createNode(void* data);
void insertNode(Node** head, void* data);
Node* searchNode(Node* head, void* data, int (*compare)(void*, void*));
void deleteNode(Node** head, void* data, int (*compare)(void*, void*), void (*freeData)(void*));
void freeList(Node** head, void (*freeData)(void*));
void displayList(Node* head, void (*display)(void*));

// Function definitions (inline to avoid multiple definition errors)
 inline Node* createNode(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for new node\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

 inline void insertNode(Node** head, void* data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

 inline Node* searchNode(Node* head, void* data, int (*compare)(void*, void*)) {
    Node* current = head;
    while (current != NULL) {
        if (compare(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

 inline void deleteNode(Node** head, void* data, int (*compare)(void*, void*), void (*freeData)(void*)) {
    if (*head == NULL) return;

    Node* current = *head;
    Node* prev = NULL;

    // If head node itself holds the data to be deleted
    if (compare(current->data, data) == 0) {
        *head = current->next;
        freeData(current->data);
        free(current);
        return;
    }

    // Search for the node to be deleted
    while (current != NULL && compare(current->data, data) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return; // Data not found

    // Unlink the node from linked list
    prev->next = current->next;
    freeData(current->data);
    free(current);
}

 inline void freeList(Node** head, void (*freeData)(void*)) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        freeData(current->data);
        free(current);
        current = next;
    }

    *head = NULL;
}

 inline void displayList(Node* head, void (*display)(void*)) {
    Node* current = head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}
#ifdef __cplusplus  
}  
#endif  

#endif //closing of universal header file linked list closing 
