#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node *createNode(int value) {
    struct Node *node = malloc(sizeof *node);
    if (!node) { fprintf(stderr, "Memory allocation failed\n"); exit(EXIT_FAILURE); }
    node->data = value; node->next = NULL; return node;
}
void insertEnd(struct Node **head, int value) {
    struct Node *node = createNode(value);
    if (!*head) { *head = node; return; }
    struct Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}
void insertBeginning(struct Node **head, int value) {
    struct Node *node = createNode(value);
    node->next = *head;
    *head = node;
}
int deleteValue(struct Node **head, int value) {
    struct Node *cur = *head, *prev = NULL;
    while (cur && cur->data != value) { prev = cur; cur = cur->next; }
    if (!cur) return 0;
    if (!prev) *head = cur->next;
    else prev->next = cur->next;
    free(cur);
    return 1;
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
    insertEnd(&head, 10); insertEnd(&head, 20); insertEnd(&head, 30);
    printList(head);
    insertBeginning(&head, 5); printList(head);
    if (!deleteValue(&head, 20)) puts("Value not found!");
    printList(head);
    if (!deleteValue(&head, 99)) puts("Value not found!");
    freeList(head);
    return 0;
}
