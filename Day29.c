/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    // Create linked list dynamically
    for (int i = 0; i < n; i++) {
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    scanf("%d", &k);

    if (n > 0) {
        k = k % n;

        if (k != 0) {
            // Make circular
            tail->next = head;

            // Find new tail: (n-k)th node
            struct Node *temp = head;
            for (int i = 1; i < n - k; i++)
                temp = temp->next;

            // New head
            head = temp->next;

            // Break circle
            temp->next = NULL;
        }
    }

    // Print result
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }

    // Free memory
    temp = head;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}