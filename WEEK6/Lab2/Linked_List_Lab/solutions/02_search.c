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

int findFirst(const Node *head, int target) {
    int index = 0;
    while (head != NULL) {
        if (head->data == target) {
            return index;
        }
        head = head->next;
        ++index;
    }
    return -1;
}

int main(void) {
    Node *head = NULL;
    printf("Empty search: %d\n", findFirst(head, 20));
    int values[] = {10, 20, 30, 20};
    for (int i = 0; i < 4; ++i) append(&head, values[i]);
    printList(head);
    printf("Find 10: %d\n", findFirst(head, 10));
    printf("Find 20: %d\n", findFirst(head, 20));
    printf("Find 99: %d\n", findFirst(head, 99));
    freeList(head);
    return 0;
}
