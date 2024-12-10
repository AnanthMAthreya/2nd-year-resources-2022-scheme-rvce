#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

// Define the structure for each node (line) in the doubly linked list
typedef struct Node {
    char line[MAX_LINE_LENGTH];  // String to store text line (80 characters max)
    struct Node* Left;           // Pointer to the left node
    struct Node* Right;          // Pointer to the right node
} Node;

// Global pointer to represent the start of the list
Node* Start = NULL;

// Function prototypes
Node* createNode(const char* text);
void addLine(const char* text);
void displayText();
void insertAtPosition(int position, const char* text);
void deleteAtPosition(int position);

int main() {
    char buffer[MAX_LINE_LENGTH];
    int choice, position;

    // Step 2: Accept lines of text and store in the list
    printf("Enter lines of text (type 'End of Text' to finish):\n");
    while (1) {
        fgets(buffer, MAX_LINE_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Step 4: Stop if the input is "End of Text"
        if (strcmp(buffer, "End of Text") == 0) {
            break;
        }
        addLine(buffer); // Step 5-6: Add the line to the list
    }

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert at Position\n2. Delete at Position\n3. Display Text\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // To clear the newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                getchar(); // To clear the newline character from input buffer
                printf("Enter text to insert: ");
                fgets(buffer, MAX_LINE_LENGTH, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                insertAtPosition(position, buffer);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 3:
                displayText();
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

// Function to create a new node with the given text
Node* createNode(const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newNode->line, text, MAX_LINE_LENGTH);
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

// Function to add a line of text to the end of the doubly linked list
void addLine(const char* text) {
    Node* New = createNode(text);

    if (Start == NULL) { // If the list is empty
        Start = New;
    } else {
        Node* temp = Start;
        while (temp->Right != NULL) {
            temp = temp->Right;
        }
        temp->Right = New;
        New->Left = temp;
    }
}

// Function to display all lines in the text
void displayText() {
    Node* temp = Start;

    if (Start == NULL) {
        printf("No text exists.\n");
        return;
    }

    printf("Text:\n");
    while (temp != NULL) {
        printf("%s\n", temp->line);
        temp = temp->Right;
    }
}

// Function to insert a line of text at a specific position
void insertAtPosition(int position, const char* text) {
    Node* New = createNode(text);

    if (Start == NULL) { // If the list is empty
        Start = New;
    } else {
        if (position == 1) { // Insert at the start
            New->Right = Start;
            Start->Left = New;
            Start = New;
        } else { // Insert at position P
            Node* temp = Start;
            for (int i = 1; i < position - 1 && temp->Right != NULL; i++) {
                temp = temp->Right;
            }
            New->Right = temp->Right;
            New->Left = temp;
            if (temp->Right != NULL) {
                temp->Right->Left = New;
            }
            temp->Right = New;
        }
    }
    printf("Inserted text at position %d: %s\n", position, text);
}

// Function to delete a line of text at a specific position
void deleteAtPosition(int position) {
    if (Start == NULL) { // If the list is empty
        printf("No text exists.\n");
        return;
    }

    Node* temp = Start;

    if (position == 1) { // Delete the first node
        Start = Start->Right;
        if (Start != NULL) {
            Start->Left = NULL;
        }
        free(temp);
    } else { // Delete at position P
        Node* Previous = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            Previous = temp;
            temp = temp->Right;
        }
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        Previous->Right = temp->Right;
        if (temp->Right != NULL) {
            temp->Right->Left = Previous;
        }
        free(temp);
    }
    printf("Deleted text at position %d.\n", position);
}
