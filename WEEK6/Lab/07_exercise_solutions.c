#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node { int data; struct Node *next; };
struct Node *createNode(int value) {
    struct Node *p = malloc(sizeof *p);
    if (!p) exit(EXIT_FAILURE);
    p->data = value; p->next = NULL; return p;
}
void insertEnd(struct Node **head, int value) {
    struct Node *p = createNode(value);
    if (!*head) { *head = p; return; }
    struct Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = p;
}
int countNodes(const struct Node *head) {
    int count = 0;
    for (const struct Node *cur = head; cur; cur = cur->next) count++;
    return count;
}
int search(const struct Node *head, int value) {
    for (const struct Node *cur = head; cur; cur = cur->next)
        if (cur->data == value) return 1;
    return 0;
}
/* Preconditions: head != NULL. */
int findMax(const struct Node *head) {
    assert(head != NULL);
    int maximum = head->data;
    for (const struct Node *cur = head->next; cur; cur = cur->next)
        if (cur->data > maximum) maximum = cur->data;
    return maximum;
}
void reverseList(struct Node **head) {
    struct Node *prev = NULL, *cur = *head;
    while (cur) {
        struct Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
void printList(const struct Node *head) {
    for (const struct Node *cur = head; cur; cur = cur->next) printf("%d -> ", cur->data);
    puts("NULL");
}
void freeList(struct Node *head) {
    while (head) { struct Node *next = head->next; free(head); head = next; }
}
int main(void) {
    struct Node *head = NULL;
    insertEnd(&head, 10); insertEnd(&head, 50); insertEnd(&head, 20);
    assert(countNodes(head) == 3);
    assert(search(head, 50) == 1);
    assert(search(head, 99) == 0);
    assert(findMax(head) == 50);
    printList(head);
    reverseList(&head);
    printList(head);
    assert(head->data == 20 && head->next->data == 50 && head->next->next->data == 10);
    freeList(head);
    puts("All checks passed.");
    return 0;
}
