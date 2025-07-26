#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Append node to the list
void append(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }

    /*Use struct Node* head when you don't need to modify the actual head.

Use struct Node** head when you need to change or update the head itself.

*/
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = node;
}

// Delete even numbers
void deleteEven(struct Node** head) {
    // Remove even nodes at the head
    while (*head && (*head)->data % 2 == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // Remove even nodes from the rest
    struct Node* curr = *head;
    while (curr && curr->next) {
        if (curr->next->data % 2 == 0) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

// Display list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }

    printf("Original list: ");
    printList(head);

    deleteEven(&head);

    printf("List after deleting even numbers: ");
    printList(head);

    return 0;
}
