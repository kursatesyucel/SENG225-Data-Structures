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

void reverseList(Node **head) {
    /* TODO: Write your solution here. */

}

int main(void) {
    Node *head = NULL;
    reverseList(&head);
    printList(head);
    append(&head, 10);
    reverseList(&head);
    printList(head);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    printList(head);
    reverseList(&head);
    printList(head);
    reverseList(&head);
    printList(head);
    freeList(head);
    return 0;
}
