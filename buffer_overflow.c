#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct node {
    int value;
    struct node *next;
} node;

// Function prototypes
node* insert(node *head, int value);
void printList(node *head);
void freeList(node *head);
void parseCommandsFromFile(char* filename, node** head);
void* threadFunc(void* arg);

int main() {
    node* head = NULL;
    int num;

    while (scanf("%d", &num) != EOF) { // Read numbers from stdin until EOF
        head = insert(head, num);
    }

    printList(head); // Print the list at the end
    freeList(head); // Free the list

    return 0;
}

// Insert a new node at the beginning of the list
node* insert(node *head, int value) {
    node *newNode = malloc(sizeof(node));
    if (!newNode) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// Print all values in the list
void printList(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Free all nodes in the list
void freeList(node *head) {
    node *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void parseCommandsFromFile(char* filename, node** head) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Example command: ADD 10
        if (strncmp(line, "ADD", 3) == 0) {
            int value = atoi(line + 4);
            *head = insert(*head, value);
        } else if (strncmp(line, "PRINT", 5) == 0) {
            printList(*head);
        } // Add more commands as needed
    }

    fclose(file);
}
void* threadFunc(void* arg) {
    // Perform operations on the list
    // Example: insert((node**)arg, 10); // Adjust as necessary
    return NULL; // Thread functions should return a pointer
}
