#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node to the linked list
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

// Function to detect cycle
int hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move slow by 1 step
        fast = fast->next->next;    // move fast by 2 steps

        if (slow == fast)           // if slow and fast meet, cycle exists
            return 1;
    }
    return 0;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter the position to make cycle (enter -1 for no cycle): ");
    scanf("%d", &pos);

    // Create cycle if position is valid
    if (pos >= 0) {
        struct Node* temp = head;
        struct Node* join = NULL;
        int count = 0;

        while (temp->next != NULL) {
            if (count == pos) {
                join = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = join; // creating the cycle
    }

    if (hasCycle(head))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
