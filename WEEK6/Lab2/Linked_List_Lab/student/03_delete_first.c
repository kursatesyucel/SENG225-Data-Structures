#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(const Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    puts("NULL");
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

void append(Node **head, int value) {
    Node *node = createNode(value);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

int deleteFirst(Node **head, int target) {
    /* TODO: Write your solution here. */

}

int main(void) {
    Node *head = NULL;
    printf("Delete from empty: %d\n", deleteFirst(&head, 20));
    int values[] = {10, 20, 30, 20};
    for (int i = 0; i < 4; ++i) append(&head, values[i]);
    printList(head);
    printf("Delete 20: %d\n", deleteFirst(&head, 20));
    printList(head);
    printf("Delete 10: %d\n", deleteFirst(&head, 10));
    printList(head);
    printf("Delete 20: %d\n", deleteFirst(&head, 20));
    printList(head);
    printf("Delete 99: %d\n", deleteFirst(&head, 99));
    printList(head);
    printf("Delete 30: %d\n", deleteFirst(&head, 30));
    printList(head);
    freeList(head);
    return 0;
}
