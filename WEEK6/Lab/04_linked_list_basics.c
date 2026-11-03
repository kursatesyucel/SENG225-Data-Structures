#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node *createNode(int value) {
    struct Node *node = malloc(sizeof *node);
    if (!node) { fprintf(stderr, "Memory allocation failed\n"); exit(EXIT_FAILURE); }
    node->data = value;
    node->next = NULL;
    return node;
}

void insertEnd(struct Node **head, int value) {
    struct Node *node = createNode(value);
    if (!*head) { *head = node; return; }
    struct Node *current = *head;
    while (current->next) current = current->next;
    current->next = node;
}

void printList(const struct Node *head) {
    for (const struct Node *cur = head; cur; cur = cur->next)
        printf("%d -> ", cur->data);
    puts("NULL");
}

void freeList(struct Node *head) {
    while (head) { struct Node *next = head->next; free(head); head = next; }
}

int main(void) {
    struct Node *head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printList(head);
    freeList(head);
    return 0;
}
