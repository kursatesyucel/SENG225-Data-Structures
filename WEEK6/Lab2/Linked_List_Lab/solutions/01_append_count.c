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

int countNodes(const Node *head) {
    int count = 0;
    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

int main(void) {
    Node *head = NULL;
    printList(head);
    printf("Count: %d\n", countNodes(head));
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printList(head);
    printf("Count: %d\n", countNodes(head));
    freeList(head);
    return 0;
}
