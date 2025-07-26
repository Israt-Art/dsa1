#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count occurrences of num
int countOccurrences(struct Node* head, int num) {
    int count = 0;
    while (head != NULL) {
        if (head->data == num) {
            count++;
        }
        head = head->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, value, num;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    printf("Enter number to count: ");
    scanf("%d", &num);

    int result = countOccurrences(head, num);
    printf("Occurrences of %d: %d\n", num, result);

    return 0;
}
