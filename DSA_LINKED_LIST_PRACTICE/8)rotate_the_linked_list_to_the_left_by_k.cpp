#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node to linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("\n");
}

// Function to rotate linked list to left by k places
void rotateLeft(struct Node** head, int k) {
    if (*head == NULL || k == 0) return;

    struct Node* current = *head;

    // Count the number of nodes
    int count = 1;
    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    // If k >= count, rotate only by k % count
    k = k % count;
    if (k == 0) return;

    // Connect last node to head to make it circular temporarily
    current->next = *head;

    // Move to the (k)th node
    struct Node* temp = *head;
    for (int i = 0; i < k - 1; i++) {
        temp = temp->next;
    }

    // New head is (k+1)th node
    *head = temp->next;

    // Break the circle
    temp->next = NULL;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original List: ");
    printList(head);

    rotateLeft(&head, k);

    printf("List after rotating left by %d places: ", k);
    printList(head);

    return 0;
}

