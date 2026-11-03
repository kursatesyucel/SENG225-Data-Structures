/* SENG 225: complete these functions. Build: gcc -std=c11 -Wall -Wextra -pedantic 06_student_exercises.c -o exercises */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
void freeList(struct Node *head) {
    while (head) { struct Node *next = head->next; free(head); head = next; }
}
void printList(const struct Node *head) {
    for (const struct Node *cur = head; cur; cur = cur->next) printf("%d -> ", cur->data);
    puts("NULL");
}

/* TODO 1: Return the number of nodes (empty list = 0). */
int countNodes(const struct Node *head) {
    (void)head;
    return -1; /* replace with your implementation */
}
/* TODO 2: Return 1 if found; otherwise 0. */
int search(const struct Node *head, int value) {
    (void)head; (void)value;
    return -1; /* replace */
}
/* TODO 3: For non-empty lists, return the maximum data value. */
int findMax(const struct Node *head) {
    (void)head;
    return INT_MIN; /* replace; caller guarantees a non-empty list */
}
/* TODO 4: Reverse the links in-place (do not allocate nodes). */
void reverseList(struct Node **head) {
    (void)head;
    /* write your implementation here */
}
int main(void) {
    struct Node *head = NULL;
    insertEnd(&head, 10); insertEnd(&head, 50); insertEnd(&head, 20);
    printList(head);
    printf("count = %d (expected 3)\n", countNodes(head));
    printf("search 50 = %d (expected 1)\n", search(head, 50));
    printf("search 99 = %d (expected 0)\n", search(head, 99));
    printf("max = %d (expected 50)\n", findMax(head));
    reverseList(&head);
    printList(head); /* expected 20 -> 50 -> 10 -> NULL */
    freeList(head);
    return 0;
}
