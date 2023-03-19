#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// ZEYNEP CINDEMIR 201401012 Q3

// Node structure
struct listNode {
    int data;
    struct listNode *nextPtr;
};

// Typedefs
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// Function prototypes
ListNodePtr createNode(int data);
void insertAtBeginning(ListNodePtr *head, int data);
void insertAtEnd(ListNodePtr *head, int data);
void insertAtPosition(ListNodePtr *head, int data, int position);
void deleteNode(ListNodePtr *head, int data);
void reverseList(ListNodePtr *head);
void printList(ListNodePtr head);

int main() {
    // Create an empty linked list
    ListNodePtr head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 11);
    printf("Linked list after inserting at beginning: (2-3-5-7-11)\n");
    printList(head);

    // Insert node at the end
    insertAtEnd(&head, 13);
    printf("Linked list after inserting at end: (13)\n");
    printList(head);

    // Insert node at position
    insertAtPosition(&head, 17, 3);
    printf("Linked list after inserting at position 3: (17)\n");
    printList(head);

    // Insert node at beginning
    insertAtBeginning(&head, 19);
    printf("Linked list after inserting at beginning: (19)\n");
    printList(head);

    // Delete node
    deleteNode(&head, 3);
    printf("Linked list after deleting node with data 3:\n");
    printList(head);

    // Reverse list
    reverseList(&head);
    printf("Linked list after reversing:\n");
    printList(head);

    // Print final list
    printf("Final linked list positions:\n");
    printList(head);

    return 0;
}

// Create a new node with the given integer data
ListNodePtr createNode(int data) {
    ListNodePtr newNode = malloc(sizeof(ListNode));     // Allocate memory for the new node
    if (newNode != NULL) {                              // Check if the memory was allocated successfully
        newNode->data = data;                           // Set the data of the new node
        newNode->nextPtr = NULL;                        // Set the next pointer of the new node to NULL
    }
    return newNode;                                     // Return the new node
}

// Insert a new node with the given integer data at the beginning of the linked list
void insertAtBeginning(ListNodePtr *head, int data) {
    ListNodePtr newNode = createNode(data);            // Create a new node with the given data
    if (newNode != NULL) {                             // Check if the node was created successfully
        newNode->nextPtr = *head;                      // Set the next pointer of the new node to the current head
        *head = newNode;                               // Set the head to the new node
    }
}

// Insert a new node with the given integer data at the end of the linked list
void insertAtEnd(ListNodePtr *head, int data) {
    ListNodePtr newNode = createNode(data);             // Create a new node with the given data
    if (newNode != NULL) {                              // Check if the node was created successfully
        if (*head == NULL) {
            *head = newNode;
        } else {                                        // Find the last node in the list
            ListNodePtr current = *head;
            while (current->nextPtr != NULL) {
                current = current->nextPtr;
            }
            current->nextPtr = newNode;                 // Set the next pointer of the last node to the new node
        }
    }
}

// Insert a new node with the given integer data at the given position in the linked list
void insertAtPosition(ListNodePtr *head, int data, int position) {
    if (position <= 0) {
        insertAtBeginning(head, data);                  // Insert at the beginning if the position is 0 or less
    } else {
        ListNodePtr newNode = createNode(data);         // Create a new node with the given data
        if (newNode != NULL) {                          // Check if the node was created successfully
            ListNodePtr current = *head;
            int i = 1;
            while (current != NULL && i < position) {   // Find the node at the given position
                current = current-> nextPtr;
                i++;
            }
            if (current != NULL) {                      // Insert the new node after the node at the given position
                newNode->nextPtr = current->nextPtr;
                current->nextPtr = newNode;
            }
        }
    }
}

// Delete the first node with the given integer data from the linked list
void deleteNode(ListNodePtr *head, int data) {
    if (*head != NULL) {                                    // Check if the list is not empty
        ListNodePtr current = *head;                        // Find the node with the given data
        ListNodePtr previous = NULL;                        // Keep track of the previous node
        while (current != NULL && current->data != data) {  // Check if the current node is not NULL and the data does not match
            previous = current;
            current = current->nextPtr;
        }
        if (current != NULL) {                              // Delete the node if it was found
            if (previous == NULL) {                         // Check if the node to be deleted is the head
                *head = current->nextPtr;
            } else {                                        // Delete the node by changing the next pointer of the previous node
                previous->nextPtr = current->nextPtr;
            }
            free(current);                                  // Free the memory of the deleted node
        }
    }
}

// Reverse the linked list
void reverseList(ListNodePtr *head) {
    ListNodePtr previous = NULL;
    ListNodePtr current = *head;
    ListNodePtr next = NULL;
    while (current != NULL) {               // Iterate through the list
        next = current->nextPtr;            // Reverse the next pointer of the current node
        current->nextPtr = previous;        // Move the pointers one position ahead
        previous = current;                 // Update the previous and current pointers 
        current = next;                     // Update the current and next pointers
    }
    *head = previous;
}

// Print the linked list
void printList(ListNodePtr head) {
    ListNodePtr current = head;         // Iterate through the list
    while (current != NULL) {           // Print the data of each node
        printf("%d ", current->data);   // Move the pointer to the next node
        current = current->nextPtr;     // Print a new line at the end
    }
    printf("\n");                       // Print a new line at the end
}
